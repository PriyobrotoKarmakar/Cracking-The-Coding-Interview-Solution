class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detect_cycle(head):
    """
    Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    Time Complexity: O(N) where N is the length of the linked list
    Space Complexity: O(1)
    """
    if not head or not head.next:
        return None
    
    # Phase 1: Detect if there is a cycle
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next       # Move slow pointer by 1 step
        fast = fast.next.next  # Move fast pointer by 2 steps
        
        if slow is fast:  # Cycle detected
            break
    
    # Check if we found a cycle
    if not fast or not fast.next:
        return None  # No cycle
    
    # Phase 2: Find the start of the cycle
    slow = head
    while slow is not fast:
        slow = slow.next
        fast = fast.next
    
    return slow  # Start of the cycle

def detect_cycle_with_set(head):
    """
    Alternative approach using a hash set (not optimized for space)
    Time Complexity: O(N)
    Space Complexity: O(N)
    """
    visited = set()
    
    current = head
    while current:
        if current in visited:
            return current  # Found the cycle start
        
        visited.add(current)
        current = current.next
    
    return None  # No cycle

def create_linked_list(arr):
    """Helper function to create a linked list from an array"""
    if not arr:
        return None
    
    head = ListNode(arr[0])
    current = head
    
    for i in range(1, len(arr)):
        current.next = ListNode(arr[i])
        current = current.next
    
    return head

def print_linked_list(head, max_nodes):
    """Helper function to print a linked list (avoiding cycles)"""
    result = []
    count = 0
    
    while head and count < max_nodes:
        result.append(str(head.val))
        head = head.next
        count += 1
    
    if head:
        result.append("... (more nodes)")
    
    print(" -> ".join(result))

def main():
    # Test case 1: Create a list with a cycle: 1->2->3->4->5->3
    list1 = create_linked_list([1, 2, 3, 4, 5])
    
    # Find the tail node
    tail = list1
    while tail.next:
        tail = tail.next
    
    # Node to connect to (3rd node, value 3)
    cycle_start = list1.next.next
    tail.next = cycle_start  # Create cycle
    
    print("List with cycle (showing first few nodes):")
    print_linked_list(list1, 8)
    print(f"Cycle starts at node with value: {cycle_start.val}")
    
    # Detect cycle using both methods
    detected1 = detect_cycle(list1)
    detected2 = detect_cycle_with_set(list1)
    
    print(f"Detected cycle start (Method 1): {detected1.val if detected1 else 'None'}")
    print(f"Detected cycle start (Method 2): {detected2.val if detected2 else 'None'}")
    
    # Test case 2: No cycle
    list2 = create_linked_list([1, 2, 3, 4, 5])
    
    print("\nList without cycle:")
    print_linked_list(list2, 10)
    
    detected1 = detect_cycle(list2)
    detected2 = detect_cycle_with_set(list2)
    
    print(f"Detected cycle start (Method 1): {detected1.val if detected1 else 'None'}")
    print(f"Detected cycle start (Method 2): {detected2.val if detected2 else 'None'}")
    
    # Test case 3: Cycle at the beginning (1->1)
    list3 = ListNode(1)
    list3.next = list3  # Points to itself
    
    print("\nList with self-cycle:")
    print("1 -> 1 -> ...")
    
    detected1 = detect_cycle(list3)
    detected2 = detect_cycle_with_set(list3)
    
    print(f"Detected cycle start (Method 1): {detected1.val if detected1 else 'None'}")
    print(f"Detected cycle start (Method 2): {detected2.val if detected2 else 'None'}")
    
    # Test case 4: Empty list
    print("\nEmpty list:")
    detected1 = detect_cycle(None)
    
    print(f"Detected cycle start: {detected1.val if detected1 else 'None'}")

if __name__ == "__main__":
    main()
