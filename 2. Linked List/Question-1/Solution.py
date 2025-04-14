#!/usr/bin/env python3

# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def remove_duplicates(head):
    """
    Solution 1: Using a hash set to track seen elements
    Time Complexity: O(N) where N is the length of the linked list
    Space Complexity: O(N) for the hash set
    """
    if not head:
        return None
    
    seen = set()
    current = head
    previous = None
    
    while current:
        if current.val in seen:
            # Duplicate found, remove this node
            previous.next = current.next
        else:
            # First time seeing this value
            seen.add(current.val)
            previous = current
        current = current.next
    
    return head

def remove_duplicates_no_buffer(head):
    """
    Solution 2: Without using additional data structures
    Time Complexity: O(N²) where N is the length of the linked list
    Space Complexity: O(1) - no additional data structures used
    """
    if not head:
        return None
    
    current = head
    
    while current:
        # For each node, check all subsequent nodes for duplicates
        runner = current
        while runner.next:
            if runner.next.val == current.val:
                # Duplicate found, remove the node
                runner.next = runner.next.next
            else:
                runner = runner.next
        current = current.next
    
    return head

def remove_duplicates_pythonic(head):
    """
    Solution 3: Using Python's built-in set for a more Pythonic approach
    Time Complexity: O(N)
    Space Complexity: O(N)
    """
    if not head:
        return None
    
    # Store unique values and the new list
    unique_values = set()
    current = head
    previous = None
    
    while current:
        if current.val in unique_values:
            # Skip this node
            previous.next = current.next
        else:
            unique_values.add(current.val)
            previous = current
        current = current.next
    
    return head

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
    # Test case 1: List with duplicates
    list1 = create_linked_list([1, 2, 3, 2, 1, 4, 5])
    print(f"Original List 1: {linked_list_to_list(list1)}")
    
    list1 = remove_duplicates(list1)
    print(f"After removing duplicates (using buffer): {linked_list_to_list(list1)}")
    
    # Test case 2: List with duplicates (no buffer solution)
    list2 = create_linked_list([5, 4, 3, 2, 1, 1, 2, 3])
    print(f"Original List 2: {linked_list_to_list(list2)}")
    
    list2 = remove_duplicates_no_buffer(list2)
    print(f"After removing duplicates (no buffer): {linked_list_to_list(list2)}")
    
    # Test case 3: List with no duplicates
    list3 = create_linked_list([1, 2, 3, 4, 5])
    print(f"Original List 3: {linked_list_to_list(list3)}")
    
    list3 = remove_duplicates_pythonic(list3)
    print(f"After removing duplicates (Pythonic): {linked_list_to_list(list3)}")
    
    # Test case 4: Empty list
    list4 = None
    print(f"Original List 4: {linked_list_to_list(list4)}")
    
    list4 = remove_duplicates(list4)
    print(f"After removing duplicates: {linked_list_to_list(list4)}")
