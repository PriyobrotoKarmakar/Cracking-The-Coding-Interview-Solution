class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_palindrome(head):
    """
    Solution 1: Reverse and Compare
    Time Complexity: O(N) where N is the length of the linked list
    Space Complexity: O(N) for creating the reversed list
    """
    if not head or not head.next:
        return True
    
    # Create a reversed copy of the list
    reversed_list = reverse_and_clone(head)
    
    # Compare the original and reversed lists
    return is_equal(head, reversed_list)

def reverse_and_clone(node):
    head = None
    
    while node:
        new_node = ListNode(node.val)
        new_node.next = head
        head = new_node
        node = node.next
    
    return head

def is_equal(l1, l2):
    while l1 and l2:
        if l1.val != l2.val:
            return False
        l1 = l1.next
        l2 = l2.next
    
    return l1 is None and l2 is None

def is_palindrome_optimized(head):
    """
    Solution 2: Runner Technique (Fast and Slow Pointers)
    Time Complexity: O(N)
    Space Complexity: O(1)
    """
    if not head or not head.next:
        return True
    
    # Find the middle of the linked list using fast/slow runners
    slow = head
    fast = head
    
    # Move fast runner twice as fast as slow runner
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    # If list has odd number of elements, skip the middle element
    if fast:
        slow = slow.next
    
    # Reverse the second half of the list
    second_half = reverse(slow)
    first_half = head
    
    # Compare the first and second half
    while second_half:
        if first_half.val != second_half.val:
            return False
        first_half = first_half.next
        second_half = second_half.next
    
    return True

def reverse(head):
    prev = None
    
    while head:
        next_temp = head.next
        head.next = prev
        prev = head
        head = next_temp
    
    return prev

def is_palindrome_with_stack(head):
    """
    Solution 3: Using a Stack
    Time Complexity: O(N)
    Space Complexity: O(N/2) for the stack
    """
    if not head or not head.next:
        return True
    
    # Find the middle of the linked list using fast/slow runners
    slow = head
    fast = head
    stack = []
    
    # Push elements from first half onto stack
    while fast and fast.next:
        stack.append(slow.val)
        slow = slow.next
        fast = fast.next.next
    
    # If list has odd number of elements, skip the middle element
    if fast:
        slow = slow.next
    
    # Compare second half with first half by popping from stack
    while slow:
        if not stack or stack.pop() != slow.val:
            return False
        slow = slow.next
    
    return True

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
    # Test cases for palindromic lists
    palindrome_arrays = [
        [1, 2, 1],
        [1, 2, 2, 1],
        [1, 2, 3, 2, 1],
        [1]
    ]
    
    print("Testing palindromic lists:")
    for arr in palindrome_arrays:
        linked_list = create_linked_list(arr)
        print("List: ", end="")
        print_linked_list(linked_list)
        
        palindrome1 = is_palindrome(linked_list)
        palindrome2 = is_palindrome_optimized(linked_list)
        palindrome3 = is_palindrome_with_stack(linked_list)
        
        print(f"Is palindrome (Solution 1): {palindrome1}")
        print(f"Is palindrome (Solution 2): {palindrome2}")
        print(f"Is palindrome (Solution 3): {palindrome3}")
        print()
    
    # Test cases for non-palindromic lists
    non_palindrome_arrays = [
        [1, 2, 3],
        [1, 2, 3, 4],
        [1, 2, 3, 4, 5, 6]
    ]
    
    print("Testing non-palindromic lists:")
    for arr in non_palindrome_arrays:
        linked_list = create_linked_list(arr)
        print("List: ", end="")
        print_linked_list(linked_list)
        
        palindrome1 = is_palindrome(linked_list)
        palindrome2 = is_palindrome_optimized(linked_list)
        palindrome3 = is_palindrome_with_stack(linked_list)
        
        print(f"Is palindrome (Solution 1): {palindrome1}")
        print(f"Is palindrome (Solution 2): {palindrome2}")
        print(f"Is palindrome (Solution 3): {palindrome3}")
        print()
    
    # Edge case: empty list
    print("Edge case - Empty list:")
    palindrome1 = is_palindrome(None)
    palindrome2 = is_palindrome_optimized(None)
    palindrome3 = is_palindrome_with_stack(None)
    
    print(f"Is palindrome (Solution 1): {palindrome1}")
    print(f"Is palindrome (Solution 2): {palindrome2}")
    print(f"Is palindrome (Solution 3): {palindrome3}")

if __name__ == "__main__":
    main()
