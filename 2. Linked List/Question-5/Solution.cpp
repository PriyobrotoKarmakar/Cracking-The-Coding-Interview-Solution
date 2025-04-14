#include <iostream>
#include <vector>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Solution 1: Forward order sum (least significant digit first)
 * Time Complexity: O(max(N, M)) where N and M are the lengths of the two lists
 * Space Complexity: O(max(N, M)) for the result list
 */
ListNode* sumLists(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    ListNode* current = &dummyHead;
    int carry = 0;
    
    // Traverse both lists and add corresponding digits
    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Handle the carry
        carry = sum / 10;
        
        // Create a new node with the digit value
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
    // If there's a carry left, add another node
    if (carry > 0) {
        current->next = new ListNode(carry);
    }
    
    return dummyHead.next;
}

// Helper function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

/**
 * Solution 2: Reverse order sum (most significant digit first)
 * First we reverse the input lists, then perform addition, then reverse the result
 * Time Complexity: O(max(N, M))
 * Space Complexity: O(max(N, M))
 */
ListNode* sumListsReverse(ListNode* l1, ListNode* l2) {
    // Reverse the input lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    // Calculate the sum
    ListNode* result = sumLists(l1, l2);
    
    // Reverse the result to get the correct order
    return reverseList(result);
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to free memory of a linked list
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example 1: 7->1->6 + 5->9->2 = 2->1->9 (617 + 295 = 912)
    std::vector<int> arr1 = {7, 1, 6};
    std::vector<int> arr2 = {5, 9, 2};
    
    ListNode* l1 = createLinkedList(arr1);
    ListNode* l2 = createLinkedList(arr2);
    
    std::cout << "Example 1 (digits stored in reverse order):" << std::endl;
    std::cout << "List 1: ";
    printLinkedList(l1);
    std::cout << "List 2: ";
    printLinkedList(l2);
    
    ListNode* sum = sumLists(l1, l2);
    std::cout << "Sum: ";
    printLinkedList(sum);
    
    // Free memory
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(sum);
    
    // Example 2: Forward order (6->1->7 + 2->9->5 = 9->1->2)
    std::cout << "\nExample 2 (digits stored in forward order):" << std::endl;
    l1 = createLinkedList({6, 1, 7});
    l2 = createLinkedList({2, 9, 5});
    
    std::cout << "List 1: ";
    printLinkedList(l1);
    std::cout << "List 2: ";
    printLinkedList(l2);
    
    sum = sumListsReverse(l1, l2);
    std::cout << "Sum: ";
    printLinkedList(sum);
    
    // Free memory
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(sum);
    
    // Test edge cases
    std::cout << "\nEdge Cases:" << std::endl;
    
    // Different list lengths
    l1 = createLinkedList({7, 1, 6, 1});
    l2 = createLinkedList({5, 9, 2});
    std::cout << "Different lengths: ";
    printLinkedList(l1);
    std::cout << " + ";
    printLinkedList(l2);
    std::cout << " = ";
    sum = sumLists(l1, l2);
    printLinkedList(sum);
    
    // Free memory
    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(sum);
    
    // Empty list
    l2 = createLinkedList({5, 9, 2});
    std::cout << "\nEmpty list: ";
    sum = sumLists(nullptr, l2);
    printLinkedList(sum);
    
    // Free memory
    deleteLinkedList(l2);
    deleteLinkedList(sum);
    
    return 0;
}
