class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sum_lists(l1, l2):
    """
    Solution 1: Forward order sum (least significant digit first)
    Time Complexity: O(max(N, M)) where N and M are the lengths of the two lists
    Space Complexity: O(max(N, M)) for the result list
    """
    dummy_head = ListNode(0)
    current = dummy_head
    carry = 0
    
    # Traverse both lists and add corresponding digits
    while l1 or l2:
        sum_val = carry
        
        if l1:
            sum_val += l1.val
            l1 = l1.next
        
        if l2:
            sum_val += l2.val
            l2 = l2.next
        
        # Handle the carry
        carry = sum_val // 10
        
        # Create a new node with the digit value
        current.next = ListNode(sum_val % 10)
        current = current.next
    
    # If there's a carry left, add another node
    if carry > 0:
        current.next = ListNode(carry)
    
    return dummy_head.next

def reverse_list(head):
    """Helper function to reverse a linked list"""
    prev = None
    current = head
    
    while current:
        next_temp = current.next
        current.next = prev
        prev = current
        current = next_temp
    
    return prev

def sum_lists_reverse(l1, l2):
    """
    Solution 2: Reverse order sum (most significant digit first)
    First we reverse the input lists, then perform addition, then reverse the result
    Time Complexity: O(max(N, M))
    Space Complexity: O(max(N, M))
    """
    # Reverse the input lists
    l1 = reverse_list(l1)
    l2 = reverse_list(l2)
    
    # Calculate the sum
    result = sum_lists(l1, l2)
    
    # Reverse the result to get the correct order
    return reverse_list(result)

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

def print_linked_list(head):
    """Helper function to print a linked list"""
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print(" -> ".join(result))

def main():
    # Example 1: 7->1->6 + 5->9->2 = 2->1->9 (617 + 295 = 912)
    arr1 = [7, 1, 6]
    arr2 = [5, 9, 2]
    
    l1 = create_linked_list(arr1)
    l2 = create_linked_list(arr2)
    
    print("Example 1 (digits stored in reverse order):")
    print("List 1: ", end="")
    print_linked_list(l1)
    print("List 2: ", end="")
    print_linked_list(l2)
    
    sum_result = sum_lists(l1, l2)
    print("Sum: ", end="")
    print_linked_list(sum_result)
    
    # Example 2: Forward order (6->1->7 + 2->9->5 = 9->1->2)
    print("\nExample 2 (digits stored in forward order):")
    l1 = create_linked_list([6, 1, 7])
    l2 = create_linked_list([2, 9, 5])
    
    print("List 1: ", end="")
    print_linked_list(l1)
    print("List 2: ", end="")
    print_linked_list(l2)
    
    sum_result = sum_lists_reverse(l1, l2)
    print("Sum: ", end="")
    print_linked_list(sum_result)
    
    # Test edge cases
    print("\nEdge Cases:")
    
    # Different list lengths
    l1 = create_linked_list([7, 1, 6, 1])
    l2 = create_linked_list([5, 9, 2])
    print("Different lengths: ", end="")
    print_linked_list(l1)
    print(" + ", end="")
    print_linked_list(l2)
    print(" = ", end="")
    print_linked_list(sum_lists(l1, l2))
    
    # Empty list
    print("\nEmpty list: ", end="")
    print_linked_list(sum_lists(None, create_linked_list([5, 9, 2])))

if __name__ == "__main__":
    main()
