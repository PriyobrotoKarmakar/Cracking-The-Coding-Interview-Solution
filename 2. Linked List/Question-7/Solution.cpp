#include <iostream>
#include <vector>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Find the intersection of two linked lists
 * Time Complexity: O(A+B) where A and B are lengths of the two lists
 * Space Complexity: O(1)
 */
ListNode* getIntersection(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    
    // Find lengths of both lists
    int lengthA = 0, lengthB = 0;
    ListNode* currA = headA;
    ListNode* currB = headB;
    
    while (currA != nullptr) {
        lengthA++;
        currA = currA->next;
    }
    
    while (currB != nullptr) {
        lengthB++;
        currB = currB->next;
    }
    
    // Align the starting points
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    
    // Move the pointer of the longer list forward
    if (lengthA > lengthB) {
        for (int i = 0; i < lengthA - lengthB; i++) {
            ptrA = ptrA->next;
        }
    } else {
        for (int i = 0; i < lengthB - lengthA; i++) {
            ptrB = ptrB->next;
        }
    }
    
    // Move both pointers until they meet or reach the end
    while (ptrA != nullptr && ptrB != nullptr) {
        if (ptrA == ptrB) {
            return ptrA;  // Found intersection
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    
    return nullptr;  // No intersection
}

/**
 * Alternative solution using two pointers
 * Time Complexity: O(A+B)
 * Space Complexity: O(1)
 */
ListNode* getIntersectionAlternative(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    
    // Two pointers traverse the lists; when one reaches the end, it moves to the other list
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    
    // Both pointers will travel the same total distance and meet at the intersection point
    // or they will both be null if there's no intersection
    while (ptrA != ptrB) {
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }
    
    return ptrA;  // Either the intersection point or null
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
void deleteLinkedList(ListNode* head, ListNode* stopAt = nullptr) {
    while (head != nullptr && head != stopAt) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create test case with intersection
    ListNode* common = createLinkedList({8, 4, 5});
    
    ListNode* headA = createLinkedList({4, 1});
    ListNode* headB = createLinkedList({5, 6, 1});
    
    // Connect the lists to the common part
    ListNode* tailA = headA;
    while (tailA->next != nullptr) {
        tailA = tailA->next;
    }
    tailA->next = common;
    
    ListNode* tailB = headB;
    while (tailB->next != nullptr) {
        tailB = tailB->next;
    }
    tailB->next = common;
    
    std::cout << "List A:" << std::endl;
    printLinkedList(headA);
    std::cout << "List B:" << std::endl;
    printLinkedList(headB);
    
    // Find intersection using both methods
    ListNode* intersection1 = getIntersection(headA, headB);
    ListNode* intersection2 = getIntersectionAlternative(headA, headB);
    
    std::cout << "Intersection point value (Method 1): ";
    if (intersection1 != nullptr) {
        std::cout << intersection1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    std::cout << "Intersection point value (Method 2): ";
    if (intersection2 != nullptr) {
        std::cout << intersection2->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Test case with no intersection
    ListNode* list1 = createLinkedList({1, 2, 3});
    ListNode* list2 = createLinkedList({4, 5, 6});
    
    std::cout << "\nLists with no intersection:" << std::endl;
    printLinkedList(list1);
    printLinkedList(list2);
    
    intersection1 = getIntersection(list1, list2);
    intersection2 = getIntersectionAlternative(list1, list2);
    
    std::cout << "Intersection point value (Method 1): ";
    if (intersection1 != nullptr) {
        std::cout << intersection1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    std::cout << "Intersection point value (Method 2): ";
    if (intersection2 != nullptr) {
        std::cout << intersection2->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Test with empty list
    std::cout << "\nTest with an empty list:" << std::endl;
    intersection1 = getIntersection(nullptr, list2);
    
    std::cout << "Intersection point value: ";
    if (intersection1 != nullptr) {
        std::cout << intersection1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Clean up memory (only delete non-common parts for the first example)
    deleteLinkedList(headA, common);
    deleteLinkedList(headB, common);
    deleteLinkedList(common);
    deleteLinkedList(list1);
    deleteLinkedList(list2);
    
    return 0;
}
