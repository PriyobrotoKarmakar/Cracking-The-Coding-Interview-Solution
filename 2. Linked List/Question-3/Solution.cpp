#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Solution: Copy the data from the next node to the current node, then delete the next node
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * 
 * Note: This solution assumes that the node to be deleted is not the tail node.
 */
bool deleteMiddleNode(ListNode* node) {
    // Cannot delete last node with this method
    if (node == nullptr || node->next == nullptr) {
        return false;
    }
    
    // Copy data from the next node
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    
    // Delete the next node
    node->next = nextNode->next;
    delete nextNode;
    
    return true;
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
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* list = createLinkedList(arr, 5);
    
    cout << "Original List: ";
    printLinkedList(list);
    
    // Find the middle node (node with value 3)
    ListNode* middleNode = list->next->next; // 3rd node
    
    // Delete the middle node
    if (deleteMiddleNode(middleNode)) {
        cout << "After deleting middle node: ";
        printLinkedList(list);
    } else {
        cout << "Could not delete the node." << endl;
    }
    
    // Try to delete the last node (should fail)
    ListNode* lastNode = list;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    
    if (!deleteMiddleNode(lastNode)) {
        cout << "As expected, cannot delete the last node using this method." << endl;
    }
    
    // Clean up
    deleteLinkedList(list);
    
    return 0;
}
