#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution 1: Finding length first
// Time Complexity: O(N) where N is the length of the linked list
// Space Complexity: O(1) - constant space
ListNode* findKthToLast_length(ListNode* head, int k) {
    if (!head || k < 1) return nullptr;
    
    // First, find the length of the list
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    
    // Check if k is out of bounds
    if (k > length) return nullptr;
    
    // Then, traverse to the (length - k)th node
    current = head;
    for (int i = 0; i < length - k; i++) {
        current = current->next;
    }
    
    return current;
}

// Solution 2: Two Pointers Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
ListNode* findKthToLast_twoPointers(ListNode* head, int k) {
    if (!head || k < 1) return nullptr;
    
    ListNode* first = head;
    ListNode* second = head;
    
    // Move first pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (!first) return nullptr; // k is larger than list length
        first = first->next;
    }
    
    // Move both pointers until first reaches the end
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    return second;
}

// Solution 3: Recursive approach
// Time Complexity: O(N)
// Space Complexity: O(N) due to the recursion stack
int findKthToLast_recursive_helper(ListNode* head, int k, ListNode** result) {
    if (!head) return 0;
    
    int index = findKthToLast_recursive_helper(head->next, k, result) + 1;
    if (index == k) {
        *result = head;
    }
    
    return index;
}

ListNode* findKthToLast_recursive(ListNode* head, int k) {
    ListNode* result = nullptr;
    findKthToLast_recursive_helper(head, k, &result);
    return result;
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
    // Test case
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* list = createLinkedList(arr, 10);
    
    cout << "Linked List: ";
    printLinkedList(list);
    
    // Test all three methods
    int k = 3; // Looking for 3rd to last element
    
    ListNode* result1 = findKthToLast_length(list, k);
    cout << "Using length method, " << k << "rd to last element: " << (result1 ? result1->val : -1) << endl;
    
    ListNode* result2 = findKthToLast_twoPointers(list, k);
    cout << "Using two pointers method, " << k << "rd to last element: " << (result2 ? result2->val : -1) << endl;
    
    ListNode* result3 = findKthToLast_recursive(list, k);
    cout << "Using recursive method, " << k << "rd to last element: " << (result3 ? result3->val : -1) << endl;
    
    // Test edge cases
    ListNode* result4 = findKthToLast_twoPointers(list, 20); // k larger than list length
    cout << "k=20 (larger than list): " << (result4 ? result4->val : -1) << endl;
    
    ListNode* result5 = findKthToLast_twoPointers(list, 10); // k equals list length
    cout << "k=10 (equals list length): " << (result5 ? result5->val : -1) << endl;
    
    // Clean up
    deleteLinkedList(list);
    
    return 0;
}
