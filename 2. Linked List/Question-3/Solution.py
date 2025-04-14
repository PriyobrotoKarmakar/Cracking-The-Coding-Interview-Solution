#!/usr/bin/env python3

# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_middle_node(node):
    """
    Solution: Copy the data from the next node to the current node, then delete the next node
    Time Complexity: O(1)
    Space Complexity: O(1)
    
    Note: This solution assumes that the node to be deleted is not the tail node.
    """
    # Cannot delete last node with this method
    if node is None or node.next is None:
        return False
    
    # Copy data from the next node
    next_node = node.next
    node.val = next_node.val
    
    # Delete the next node
    node.next = next_node.next
    
    return True

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

# Helper function to get node at a specific position
def get_node_at_position(head, position):
    if not head:
        return None
    
    current = head
    for _ in range(position):
        if not current:
            return None
        current = current.next
    
    return current

# Helper function to convert a linked list to a list for printing
def linked_list_to_list(head):
    result = []
    current = head
    
    while current:
        result.append(current.val)
        current = current.next
    
    return result

if __name__ == "__main__":
    # Test case with numbers
    list_values = [1, 2, 3, 4, 5]
    linked_list = create_linked_list(list_values)
    
    print(f"Original List: {linked_list_to_list(linked_list)}")
    
    # Delete the middle node (node with value 3)
    middle_node = get_node_at_position(linked_list, 2)  # 3rd node (0-indexed)
    
    if delete_middle_node(middle_node):
        print(f"After deleting middle node: {linked_list_to_list(linked_list)}")
    else:
        print("Could not delete the node.")
    
    # Try to delete the last node (should fail)
    last_node = get_node_at_position(linked_list, 3)  # Last node after previous deletion
    
    if not delete_middle_node(last_node):
        print("As expected, cannot delete the last node using this method.")
    
    # Example from problem statement with characters
    example_values = ['a', 'b', 'c', 'd', 'e', 'f']
    example_list = create_linked_list(example_values)
    
    print(f"\nExample from problem statement - Original: {linked_list_to_list(example_list)}")
    
    # Delete node 'c'
    node_c = get_node_at_position(example_list, 2)  # 3rd node (0-indexed)
    
    if delete_middle_node(node_c):
        print(f"After deleting node 'c': {linked_list_to_list(example_list)}")
