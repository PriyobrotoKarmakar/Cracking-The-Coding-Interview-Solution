class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def get_intersection(headA, headB):
    """
    Find the intersection of two linked lists
    Time Complexity: O(A+B) where A and B are lengths of the two lists
    Space Complexity: O(1)
    """
    if not headA or not headB:
        return None
    
    # Find lengths of both lists
    def get_length(node):
        length = 0
        while node:
            length += 1
            node = node.next
        return length
    
    lengthA = get_length(headA)
    lengthB = get_length(headB)
    
    # Align the starting points
    ptrA, ptrB = headA, headB
    
    # Move the pointer of the longer list forward
    if lengthA > lengthB:
        for _ in range(lengthA - lengthB):
            ptrA = ptrA.next
    else:
        for _ in range(lengthB - lengthA):
            ptrB = ptrB.next
    
    # Move both pointers until they meet or reach the end
    while ptrA and ptrB:
        if ptrA is ptrB:  # Note: using 'is' checks for same object
            return ptrA   # Found intersection
        ptrA = ptrA.next
        ptrB = ptrB.next
    
    return None  # No intersection

def get_intersection_alternative(headA, headB):
    """
    Alternative solution using two pointers
    Time Complexity: O(A+B)
    Space Complexity: O(1)
    """
    if not headA or not headB:
        return None
    
    # Two pointers traverse the lists; when one reaches the end, it moves to the other list
    ptrA, ptrB = headA, headB
    
    # Both pointers will travel the same total distance and meet at the intersection point
    # or they will both be null if there's no intersection
    while ptrA is not ptrB:
        ptrA = headB if ptrA is None else ptrA.next
        ptrB = headA if ptrB is None else ptrB.next
    
    return ptrA  # Either the intersection point or None

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
    # Create test case with intersection
    common = create_linked_list([8, 4, 5])
    
    headA = create_linked_list([4, 1])
    headB = create_linked_list([5, 6, 1])
    
    # Connect the lists to the common part
    tailA = headA
    while tailA.next:
        tailA = tailA.next
    tailA.next = common
    
    tailB = headB
    while tailB.next:
        tailB = tailB.next
    tailB.next = common
    
    print("List A:")
    print_linked_list(headA)
    print("List B:")
    print_linked_list(headB)
    
    # Find intersection using both methods
    intersection1 = get_intersection(headA, headB)
    intersection2 = get_intersection_alternative(headA, headB)
    
    print("Intersection point value (Method 1):", 
          intersection1.val if intersection1 else "None")
    print("Intersection point value (Method 2):", 
          intersection2.val if intersection2 else "None")
    
    # Test case with no intersection
    list1 = create_linked_list([1, 2, 3])
    list2 = create_linked_list([4, 5, 6])
    
    print("\nLists with no intersection:")
    print_linked_list(list1)
    print_linked_list(list2)
    
    intersection1 = get_intersection(list1, list2)
    intersection2 = get_intersection_alternative(list1, list2)
    
    print("Intersection point value (Method 1):", 
          intersection1.val if intersection1 else "None")
    print("Intersection point value (Method 2):", 
          intersection2.val if intersection2 else "None")
    
    # Test with empty list
    print("\nTest with an empty list:")
    intersection1 = get_intersection(None, list2)
    
    print("Intersection point value:", 
          intersection1.val if intersection1 else "None")

if __name__ == "__main__":
    main()
