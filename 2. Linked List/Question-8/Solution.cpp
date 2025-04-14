#include <iostream>
#include <vector>
#include <unordered_set>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Floyd's Cycle Detection Algorithm (Tortoise and Hare)
 * Time Complexity: O(N) where N is the length of the linked list
 * Space Complexity: O(1)
 */
ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    
    // Phase 1: Detect if there is a cycle
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by 1 step
        fast = fast->next->next;     // Move fast pointer by 2 steps
        
        if (slow == fast) {  // Cycle detected
            break;
        }
    }
    
    // Check if we found a cycle
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;  // No cycle
    }
    
    // Phase 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;  // Start of the cycle
}

/**
 * Alternative approach using a hash set (not optimized for space)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
ListNode* detectCycleWithHashSet(ListNode* head) {
    std::unordered_set<ListNode*> visited;
    
    ListNode* current = head;
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return current;  // Found the cycle start
        }
        
        visited.insert(current);
        current = current->next;
    }
    
    return nullptr;  // No cycle
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

// Helper function to print a linked list (avoiding cycles)
void printLinkedList(ListNode* head, int maxNodes) {
    int count = 0;
    while (head != nullptr && count < maxNodes) {
        std::cout << head->val;
        if (head->next != nullptr && count < maxNodes - 1) {
            std::cout << " -> ";
        }
        head = head->next;
        count++;
    }
    
    if (head != nullptr) {
        std::cout << " -> ... (more nodes)";
    }
    std::cout << std::endl;
}

// Helper function to free memory of a linked list with a cycle
void deleteLinkedListWithCycle(ListNode* head, ListNode* cycleStart = nullptr) {
    std::unordered_set<ListNode*> visited;
    
    while (head != nullptr) {
        if (visited.find(head) != visited.end()) {
            break;  // Already visited this node (cycle detected)
        }
        
        visited.insert(head);
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1: Create a list with a cycle: 1->2->3->4->5->3
    ListNode* list1 = createLinkedList({1, 2, 3, 4, 5});
    ListNode* tail = list1;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    
    // Node to connect to (3rd node, value 3)
    ListNode* cycleStart = list1->next->next;
    tail->next = cycleStart;  // Create cycle
    
    std::cout << "List with cycle (showing first few nodes):" << std::endl;
    printLinkedList(list1, 8);
    std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    
    // Detect cycle using both methods
    ListNode* detected1 = detectCycle(list1);
    ListNode* detected2 = detectCycleWithHashSet(list1);
    
    std::cout << "Detected cycle start (Method 1): ";
    if (detected1 != nullptr) {
        std::cout << detected1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    std::cout << "Detected cycle start (Method 2): ";
    if (detected2 != nullptr) {
        std::cout << detected2->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Test case 2: No cycle
    ListNode* list2 = createLinkedList({1, 2, 3, 4, 5});
    
    std::cout << "\nList without cycle:" << std::endl;
    printLinkedList(list2, 10);
    
    detected1 = detectCycle(list2);
    detected2 = detectCycleWithHashSet(list2);
    
    std::cout << "Detected cycle start (Method 1): ";
    if (detected1 != nullptr) {
        std::cout << detected1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    std::cout << "Detected cycle start (Method 2): ";
    if (detected2 != nullptr) {
        std::cout << detected2->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Test case 3: Cycle at the beginning (1->1)
    ListNode* list3 = new ListNode(1);
    list3->next = list3;  // Points to itself
    
    std::cout << "\nList with self-cycle:" << std::endl;
    std::cout << "1 -> 1 -> ..." << std::endl;
    
    detected1 = detectCycle(list3);
    detected2 = detectCycleWithHashSet(list3);
    
    std::cout << "Detected cycle start (Method 1): ";
    if (detected1 != nullptr) {
        std::cout << detected1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    std::cout << "Detected cycle start (Method 2): ";
    if (detected2 != nullptr) {
        std::cout << detected2->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Test case 4: Empty list
    std::cout << "\nEmpty list:" << std::endl;
    detected1 = detectCycle(nullptr);
    
    std::cout << "Detected cycle start: ";
    if (detected1 != nullptr) {
        std::cout << detected1->val << std::endl;
    } else {
        std::cout << "None" << std::endl;
    }
    
    // Clean up memory
    deleteLinkedListWithCycle(list1);
    deleteLinkedListWithCycle(list2);
    deleteLinkedListWithCycle(list3);
    
    return 0;
}
