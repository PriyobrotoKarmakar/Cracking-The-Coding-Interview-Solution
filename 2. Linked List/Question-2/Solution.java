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
     * Solution 1: Finding the length first
     * Time Complexity: O(N) where N is the length of the linked list
     * Space Complexity: O(1) - constant space
     */
    public static ListNode findKthToLast_length(ListNode head, int k) {
        if (head == null || k < 1) return null;
        
        // First, find the length of the list
        int length = 0;
        ListNode current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        
        // Check if k is out of bounds
        if (k > length) return null;
        
        // Then, traverse to the (length - k)th node
        current = head;
        for (int i = 0; i < length - k; i++) {
            current = current.next;
        }
        
        return current;
    }
    
    /**
     * Solution 2: Two Pointers Approach
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    public static ListNode findKthToLast_twoPointers(ListNode head, int k) {
        if (head == null || k < 1) return null;
        
        ListNode first = head;
        ListNode second = head;
        
        // Move first pointer k nodes ahead
        for (int i = 0; i < k; i++) {
            if (first == null) return null; // k is larger than list length
            first = first.next;
        }
        
        // Move both pointers until first reaches the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        
        return second;
    }
    
    /**
     * Solution 3: Recursive approach
     * Time Complexity: O(N)
     * Space Complexity: O(N) due to the recursion stack
     */
    static class Index {
        int value = 0;
    }
    
    public static ListNode findKthToLast_recursive(ListNode head, int k) {
        Index idx = new Index();
        return findKthToLastRecursive(head, k, idx);
    }
    
    private static ListNode findKthToLastRecursive(ListNode head, int k, Index idx) {
        if (head == null) {
            return null;
        }
        
        ListNode node = findKthToLastRecursive(head.next, k, idx);
        idx.value++;
        
        if (idx.value == k) {
            return head;
        }
        
        return node;
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
        // Test case
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ListNode list = createLinkedList(arr);
        
        System.out.print("Linked List: ");
        printLinkedList(list);
        
        // Test all three methods
        int k = 3; // Looking for 3rd to last element
        
        ListNode result1 = findKthToLast_length(list, k);
        System.out.println("Using length method, " + k + "rd to last element: " + 
                          (result1 != null ? result1.val : -1));
        
        ListNode result2 = findKthToLast_twoPointers(list, k);
        System.out.println("Using two pointers method, " + k + "rd to last element: " + 
                          (result2 != null ? result2.val : -1));
        
        ListNode result3 = findKthToLast_recursive(list, k);
        System.out.println("Using recursive method, " + k + "rd to last element: " + 
                          (result3 != null ? result3.val : -1));
        
        // Test edge cases
        ListNode result4 = findKthToLast_twoPointers(list, 20); // k larger than list length
        System.out.println("k=20 (larger than list): " + (result4 != null ? result4.val : -1));
        
        ListNode result5 = findKthToLast_twoPointers(list, 10); // k equals list length
        System.out.println("k=10 (equals list length): " + (result5 != null ? result5.val : -1));
    }
}
