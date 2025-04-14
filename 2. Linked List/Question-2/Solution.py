#!/usr/bin/env python3

# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def find_kth_to_last_length(head, k):
    """
    Solution 1: Finding the length first
    Time Complexity: O(N) where N is the length of the linked list
    Space Complexity: O(1) - constant space
    """
    if not head or k < 1:
        return None
    
    # First, find the length of the list
    length = 0
    current = head
    while current:
        length += 1
        current = current.next
    
    # Check if k is out of bounds
    if k > length:
        return None
    
    # Then, traverse to the (length - k)th node
    current = head
    for _ in range(length - k):
        current = current.next
    
    return current

def find_kth_to_last_two_pointers(head, k):
    """
    Solution 2: Two Pointers Approach
    Time Complexity: O(N)
    Space Complexity: O(1)
    """
    if not head or k < 1:
        return None
    
    first = head
    second = head
    
    # Move first pointer k nodes ahead
    for _ in range(k):
        if not first:  # k is larger than list length
            return None
        first = first.next
    
    # Move both pointers until first reaches the end
    while first:
        first = first.next
        second = second.next
    
    return second

def find_kth_to_last_recursive(head, k):
    """
    Solution 3: Recursive Approach
    Time Complexity: O(N)
    Space Complexity: O(N) due to the recursion stack
    """
    def helper(node, k):
        if not node:
            return (None, 0)
        
        result_node, position = helper(node.next, k)
        position += 1
        
        if position == k:
            return (node, position)
        
        return (result_node, position)
    
    result, _ = helper(head, k)
    return result

def find_kth_to_last_pythonic(head, k):
    """
    Solution 4: Pythonic solution with list conversion
    Time Complexity: O(N)
    Space Complexity: O(N) for storing the nodes in a list
    """
    if not head or k < 1:
        return None
    
    # Convert linked list to a regular list
    nodes = []
    current = head
    while current:
        nodes.append(current)
        current = current.next
    
    # Check if k is out of bounds
    if k > len(nodes):
        return None
    
    # Return the kth to last element
    return nodes[-k]

# Helper function to create a linked list from a list
def create_linked_list(values):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head
    
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    
    return head

# Helper function to convert a linked list to a list for printing
def linked_list_to_list(head):
    result = []
    current = head
    
    while current:
        result.append(current.val)
        current = current.next
    
    return result

if __name__ == "__main__":
    # Test case
    list_values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    linked_list = create_linked_list(list_values)
    
    print(f"Linked List: {linked_list_to_list(linked_list)}")
    
    # Test all four methods
    k = 3  # Looking for 3rd to last element
    
    result1 = find_kth_to_last_length(linked_list, k)
    print(f"Using length method, {k}rd to last element: {result1.val if result1 else None}")
    
    result2 = find_kth_to_last_two_pointers(linked_list, k)
    print(f"Using two pointers method, {k}rd to last element: {result2.val if result2 else None}")
    
    result3 = find_kth_to_last_recursive(linked_list, k)
    print(f"Using recursive method, {k}rd to last element: {result3.val if result3 else None}")
    
    result4 = find_kth_to_last_pythonic(linked_list, k)
    print(f"Using Pythonic method, {k}rd to last element: {result4.val if result4 else None}")
    
    # Test edge cases
    result5 = find_kth_to_last_two_pointers(linked_list, 20)  # k larger than list length
    print(f"k=20 (larger than list): {result5.val if result5 else None}")
    
    result6 = find_kth_to_last_two_pointers(linked_list, 10)  # k equals list length
    print(f"k=10 (equals list length): {result6.val if result6 else None}")
    
    result7 = find_kth_to_last_two_pointers(None, k)  # Empty list
    print(f"Empty list: {result7.val if result7 else None}")
