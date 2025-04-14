#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution 1: Using a hash table to track seen elements
// Time Complexity: O(N) where N is the length of the linked list
// Space Complexity: O(N) for the hash table
ListNode* removeDuplicates(ListNode* head) {
    if (!head) return nullptr;
    
    unordered_set<int> seen;
    ListNode* current = head;
    ListNode* previous = nullptr;
    
    while (current) {
        if (seen.find(current->val) != seen.end()) {
            // Duplicate found, remove this node
            previous->next = current->next;
            delete current;
            current = previous->next;
        } else {
            // First time seeing this value
            seen.insert(current->val);
            previous = current;
            current = current->next;
        }
    }
    
    return head;
}

// Solution 2: Without using additional data structures
// Time Complexity: O(N²) where N is the length of the linked list
// Space Complexity: O(1) - no additional data structures used
ListNode* removeDuplicatesNoBuffer(ListNode* head) {
    if (!head) return nullptr;
    
    ListNode* current = head;
    
    while (current) {
        // For each node, check all subsequent nodes for duplicates
        ListNode* runner = current;
        while (runner->next) {
            if (runner->next->val == current->val) {
                // Duplicate found, remove the node
                ListNode* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    
    return head;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n <= 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to free memory of a linked list
void deleteLinkedList(ListNode* head) {
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1: List with duplicates
    int arr1[] = {1, 2, 3, 2, 1, 4, 5};
    ListNode* list1 = createLinkedList(arr1, 7);
    cout << "Original List 1: ";
    printLinkedList(list1);
    
    list1 = removeDuplicates(list1);
    cout << "After removing duplicates (using buffer): ";
    printLinkedList(list1);
    deleteLinkedList(list1);
    
    // Test case 2: List with duplicates (no buffer solution)
    int arr2[] = {5, 4, 3, 2, 1, 1, 2, 3};
    ListNode* list2 = createLinkedList(arr2, 8);
    cout << "Original List 2: ";
    printLinkedList(list2);
    
    list2 = removeDuplicatesNoBuffer(list2);
    cout << "After removing duplicates (no buffer): ";
    printLinkedList(list2);
    deleteLinkedList(list2);
    
    // Test case 3: List with no duplicates
    int arr3[] = {1, 2, 3, 4, 5};
    ListNode* list3 = createLinkedList(arr3, 5);
    cout << "Original List 3: ";
    printLinkedList(list3);
    
    list3 = removeDuplicates(list3);
    cout << "After removing duplicates: ";
    printLinkedList(list3);
    deleteLinkedList(list3);
    
    return 0;
}
