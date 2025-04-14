#include <iostream>
#include <vector>
#include <stack>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Solution 1: Reverse and Compare
 * Time Complexity: O(N) where N is the length of the linked list
 * Space Complexity: O(N) for creating the reversed list
 */
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    
    // Create a reversed copy of the list
    ListNode* reversed = reverseAndClone(head);
    
    // Compare the original and reversed lists
    return isEqual(head, reversed);
}

ListNode* reverseAndClone(ListNode* node) {
    ListNode* head = nullptr;
    
    while (node != nullptr) {
        ListNode* newNode = new ListNode(node->val);
        newNode->next = head;
        head = newNode;
        node = node->next;
    }
    
    return head;
}

bool isEqual(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return l1 == nullptr && l2 == nullptr;
}

/**
 * Solution 2: Runner Technique (Fast and Slow Pointers)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool isPalindromeOptimized(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    
    // Find the middle of the linked list using fast/slow runners
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Move fast runner twice as fast as slow runner
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // If list has odd number of elements, skip the middle element
    if (fast != nullptr) {
        slow = slow->next;
    }
    
    // Reverse the second half of the list
    ListNode* secondHalf = reverse(slow);
    ListNode* firstHalf = head;
    
    // Compare the first and second half
    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    
    while (head != nullptr) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

/**
 * Solution 3: Using a Stack
 * Time Complexity: O(N)
 * Space Complexity: O(N/2) for the stack
 */
bool isPalindromeWithStack(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    
    // Find the middle of the linked list using fast/slow runners
    ListNode* slow = head;
    ListNode* fast = head;
    std::stack<int> stack;
    
    // Push elements from first half onto stack
    while (fast != nullptr && fast->next != nullptr) {
        stack.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // If list has odd number of elements, skip the middle element
    if (fast != nullptr) {
        slow = slow->next;
    }
    
    // Compare second half with first half by popping from stack
    while (slow != nullptr) {
        int top = stack.top();
        stack.pop();
        
        if (top != slow->val) {
            return false;
        }
        
        slow = slow->next;
    }
    
    return true;
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
    // Test cases for palindromic lists
    std::vector<std::vector<int>> palindromeArrays = {
        {1, 2, 1},
        {1, 2, 2, 1},
        {1, 2, 3, 2, 1},
        {1}
    };
    
    std::cout << "Testing palindromic lists:" << std::endl;
    for (const auto& arr : palindromeArrays) {
        ListNode* list = createLinkedList(arr);
        std::cout << "List: ";
        printLinkedList(list);
        
        bool isPalindrome1 = isPalindrome(list);
        bool isPalindrome2 = isPalindromeOptimized(list);
        bool isPalindrome3 = isPalindromeWithStack(list);
        
        std::cout << "Is palindrome (Solution 1): " << (isPalindrome1 ? "true" : "false") << std::endl;
        std::cout << "Is palindrome (Solution 2): " << (isPalindrome2 ? "true" : "false") << std::endl;
        std::cout << "Is palindrome (Solution 3): " << (isPalindrome3 ? "true" : "false") << std::endl;
        std::cout << std::endl;
        
        deleteLinkedList(list);
    }
    
    // Test cases for non-palindromic lists
    std::vector<std::vector<int>> nonPalindromeArrays = {
        {1, 2, 3},
        {1, 2, 3, 4},
        {1, 2, 3, 4, 5, 6}
    };
    
    std::cout << "Testing non-palindromic lists:" << std::endl;
    for (const auto& arr : nonPalindromeArrays) {
        ListNode* list = createLinkedList(arr);
        std::cout << "List: ";
        printLinkedList(list);
        
        bool isPalindrome1 = isPalindrome(list);
        bool isPalindrome2 = isPalindromeOptimized(list);
        bool isPalindrome3 = isPalindromeWithStack(list);
        
        std::cout << "Is palindrome (Solution 1): " << (isPalindrome1 ? "true" : "false") << std::endl;
        std::cout << "Is palindrome (Solution 2): " << (isPalindrome2 ? "true" : "false") << std::endl;
        std::cout << "Is palindrome (Solution 3): " << (isPalindrome3 ? "true" : "false") << std::endl;
        std::cout << std::endl;
        
        deleteLinkedList(list);
    }
    
    // Edge case: empty list
    std::cout << "Edge case - Empty list:" << std::endl;
    bool isPalindrome1 = isPalindrome(nullptr);
    bool isPalindrome2 = isPalindromeOptimized(nullptr);
    bool isPalindrome3 = isPalindromeWithStack(nullptr);
    
    std::cout << "Is palindrome (Solution 1): " << (isPalindrome1 ? "true" : "false") << std::endl;
    std::cout << "Is palindrome (Solution 2): " << (isPalindrome2 ? "true" : "false") << std::endl;
    std::cout << "Is palindrome (Solution 3): " << (isPalindrome3 ? "true" : "false") << std::endl;
    
    return 0;
}
