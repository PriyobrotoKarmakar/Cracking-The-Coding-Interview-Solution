public class Solution {
    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;
        
        ListNode(int x) {
            val = x;
            next = null;
        }
    }
    
    /**
     * Find the intersection of two linked lists
     * Time Complexity: O(A+B) where A and B are lengths of the two lists
     * Space Complexity: O(1)
     */
    public static ListNode getIntersection(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        
        // Find lengths of both lists
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        
        // Align the starting points
        ListNode ptrA = headA;
        ListNode ptrB = headB;
        
        // Move the pointer of the longer list forward
        if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++) {
                ptrA = ptrA.next;
            }
        } else {
            for (int i = 0; i < lengthB - lengthA; i++) {
                ptrB = ptrB.next;
            }
        }
        
        // Move both pointers until they meet or reach the end
        while (ptrA != null && ptrB != null) {
            if (ptrA == ptrB) {
                return ptrA;  // Found intersection
            }
            ptrA = ptrA.next;
            ptrB = ptrB.next;
        }
        
        return null;  // No intersection
    }
    
    /**
     * Alternative solution using two pointers
     * Time Complexity: O(A+B)
     * Space Complexity: O(1)
     */
    public static ListNode getIntersectionAlternative(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        
        // Two pointers traverse the lists; when one reaches the end, it moves to the other list
        ListNode ptrA = headA;
        ListNode ptrB = headB;
        
        // Both pointers will travel the same total distance and meet at the intersection point
        // or they will both be null if there's no intersection
        while (ptrA != ptrB) {
            ptrA = (ptrA == null) ? headB : ptrA.next;
            ptrB = (ptrB == null) ? headA : ptrB.next;
        }
        
        return ptrA;  // Either the intersection point or null
    }
    
    // Helper function to get the length of a linked list
    private static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }
    
    // Helper function to create a linked list from an array
    public static ListNode createLinkedList(int[] arr) {
        if (arr == null || arr.length == 0) return null;
        
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        
        return head;
    }
    
    // Helper function to print a linked list
    public static void printLinkedList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) {
                System.out.print(" -> ");
            }
            head = head.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        // Create test case with intersection
        ListNode common = createLinkedList(new int[]{8, 4, 5});
        
        ListNode headA = createLinkedList(new int[]{4, 1});
        ListNode headB = createLinkedList(new int[]{5, 6, 1});
        
        // Connect the lists to the common part
        ListNode tailA = headA;
        while (tailA.next != null) {
            tailA = tailA.next;
        }
        tailA.next = common;
        
        ListNode tailB = headB;
        while (tailB.next != null) {
            tailB = tailB.next;
        }
        tailB.next = common;
        
        System.out.println("List A:");
        printLinkedList(headA);
        System.out.println("List B:");
        printLinkedList(headB);
        
        // Find intersection using both methods
        ListNode intersection1 = getIntersection(headA, headB);
        ListNode intersection2 = getIntersectionAlternative(headA, headB);
        
        System.out.println("Intersection point value (Method 1): " + 
                          (intersection1 != null ? intersection1.val : "None"));
        System.out.println("Intersection point value (Method 2): " + 
                          (intersection2 != null ? intersection2.val : "None"));
        
        // Test case with no intersection
        ListNode list1 = createLinkedList(new int[]{1, 2, 3});
        ListNode list2 = createLinkedList(new int[]{4, 5, 6});
        
        System.out.println("\nLists with no intersection:");
        printLinkedList(list1);
        printLinkedList(list2);
        
        intersection1 = getIntersection(list1, list2);
        intersection2 = getIntersectionAlternative(list1, list2);
        
        System.out.println("Intersection point value (Method 1): " + 
                          (intersection1 != null ? intersection1.val : "None"));
        System.out.println("Intersection point value (Method 2): " + 
                          (intersection2 != null ? intersection2.val : "None"));
        
        // Test with empty list
        System.out.println("\nTest with an empty list:");
        intersection1 = getIntersection(null, list2);
        
        System.out.println("Intersection point value: " + 
                          (intersection1 != null ? intersection1.val : "None"));
    }
}
