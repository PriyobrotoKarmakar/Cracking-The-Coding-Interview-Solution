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
     * Solution 1: Forward order sum (least significant digit first)
     * Time Complexity: O(max(N, M)) where N and M are the lengths of the two lists
     * Space Complexity: O(max(N, M)) for the result list
     */
    public static ListNode sumLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode current = dummyHead;
        int carry = 0;
        
        // Traverse both lists and add corresponding digits
        while (l1 != null || l2 != null) {
            int sum = carry;
            
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            
            // Handle the carry
            carry = sum / 10;
            
            // Create a new node with the digit value
            current.next = new ListNode(sum % 10);
            current = current.next;
        }
        
        // If there's a carry left, add another node
        if (carry > 0) {
            current.next = new ListNode(carry);
        }
        
        return dummyHead.next;
    }
    
    /**
     * Solution 2: Reverse order sum (most significant digit first)
     * First we reverse the input lists, then perform addition, then reverse the result
     * Time Complexity: O(max(N, M))
     * Space Complexity: O(max(N, M))
     */
    public static ListNode sumListsReverse(ListNode l1, ListNode l2) {
        // Reverse the input lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        // Calculate the sum
        ListNode result = sumLists(l1, l2);
        
        // Reverse the result to get the correct order
        return reverseList(result);
    }
    
    // Helper function to reverse a linked list
    private static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
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
        // Example 1: 7->1->6 + 5->9->2 = 2->1->9 (617 + 295 = 912)
        int[] arr1 = {7, 1, 6};
        int[] arr2 = {5, 9, 2};
        
        ListNode l1 = createLinkedList(arr1);
        ListNode l2 = createLinkedList(arr2);
        
        System.out.println("Example 1 (digits stored in reverse order):");
        System.out.print("List 1: ");
        printLinkedList(l1);
        System.out.print("List 2: ");
        printLinkedList(l2);
        
        ListNode sum = sumLists(l1, l2);
        System.out.print("Sum: ");
        printLinkedList(sum);
        
        // Example 2: Forward order (6->1->7 + 2->9->5 = 9->1->2)
        System.out.println("\nExample 2 (digits stored in forward order):");
        System.out.print("List 1: ");
        printLinkedList(createLinkedList(new int[]{6, 1, 7}));
        System.out.print("List 2: ");
        printLinkedList(createLinkedList(new int[]{2, 9, 5}));
        
        sum = sumListsReverse(createLinkedList(new int[]{6, 1, 7}), 
                              createLinkedList(new int[]{2, 9, 5}));
        System.out.print("Sum: ");
        printLinkedList(sum);
        
        // Test edge cases
        System.out.println("\nEdge Cases:");
        
        // Different list lengths
        l1 = createLinkedList(new int[]{7, 1, 6, 1});
        l2 = createLinkedList(new int[]{5, 9, 2});
        System.out.print("Different lengths: ");
        printLinkedList(l1);
        System.out.print(" + ");
        printLinkedList(l2);
        System.out.print(" = ");
        printLinkedList(sumLists(l1, l2));
        
        // Empty list
        System.out.print("\nEmpty list: ");
        printLinkedList(sumLists(null, createLinkedList(new int[]{5, 9, 2})));
    }
}
