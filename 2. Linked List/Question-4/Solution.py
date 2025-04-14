#!/usr/bin/env python3

# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def partition(head, x):
    """
    Solution 1: Creating two separate lists and merging them
    Time Complexity: O(N) where N is the length of the linked list
    Space Complexity: O(1) as we're just rearranging pointers
    """
    if not head:
        return None
    
    before_start = None
    before_end = None
    after_start = None
    after_end = None
    
    # Partition list
    current = head
    while current:
        next_node = current.next
        current.next = None
        
        if current.val < x:
            # Insert node into end of before list
            if not before_start:
                before_start = current
                before_end = current
            else:
                before_end.next = current
                before_end = current
        else:
            # Insert node into end of after list
            if not after_start:
                after_start = current
                after_end = current
            else:
                after_end.next = current
                after_end = current
        
        current = next_node
    
    # If there's no "before" list, return the "after" list
    if not before_start:
        return after_start
    
    # Merge the two lists
    before_end.next = after_start
    
    return before_start

def partition_alternative(head, x):
    """
    Solution 2: Creating a new list with elements less than x at the front
    Time Complexity: O(N)
    Space Complexity: O(1)
    """
    if not head:
        return None
    
    # Create two dummy heads for two separate lists
    less_dummy = ListNode(0)
    greater_dummy = ListNode(0)
    
    # Pointers to the current end of each list
    less = less_dummy
    greater = greater_dummy
    
    # Traverse the original list
    current = head
    while current:
        if current.val < x:
            less.next = current
            less = current
        else:
            greater.next = current
            greater = current
        
        current = current.next
    
    # Terminate the lists
    greater.next = None
    less.next = greater_dummy.next
    
    return less_dummy.next

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
    # Example from the problem statement
    list_values = [3, 5, 8, 5, 10, 2, 1]
    linked_list = create_linked_list(list_values)
    
    print(f"Original List: {linked_list_to_list(linked_list)}")
    
    partition_value = 5
    print(f"Partition value: {partition_value}")
    
    partitioned = partition(linked_list, partition_value)
    print(f"After partitioning (Solution 1): {linked_list_to_list(partitioned)}")
    
    # Test with alternative solution
    linked_list = create_linked_list(list_values)  # Recreate the list
    partitioned2 = partition_alternative(linked_list, partition_value)
    print(f"After partitioning (Solution 2): {linked_list_to_list(partitioned2)}")
    
    # Test edge cases
    
    # 1. All elements less than partition value
    list_values2 = [1, 2, 3, 4]
    linked_list = create_linked_list(list_values2)
    print(f"\nAll elements less than partition: {linked_list_to_list(linked_list)}")
    
    partitioned = partition(linked_list, 5)
    print(f"After partitioning: {linked_list_to_list(partitioned)}")
    
    # 2. All elements greater than or equal to partition value
    list_values3 = [5, 6, 7, 8]
    linked_list = create_linked_list(list_values3)
    print(f"\nAll elements greater than partition: {linked_list_to_list(linked_list)}")
    
    partitioned = partition(linked_list, 5)
    print(f"After partitioning: {linked_list_to_list(partitioned)}")
    
    # 3. Empty list
    print(f"\nEmpty list partitioning: {linked_list_to_list(partition(None, 5))}")
    
    # 4. List with one element
    list_values4 = [5]
    linked_list = create_linked_list(list_values4)
    print(f"\nList with one element: {linked_list_to_list(linked_list)}")
    
    partitioned = partition(linked_list, 5)
    print(f"After partitioning: {linked_list_to_list(partitioned)}")
