import java.util.HashSet;

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
     * Solution 1: Using a HashSet to track seen elements
     * Time Complexity: O(N) where N is the length of the linked list
     * Space Complexity: O(N) for the HashSet
     */
    public static ListNode removeDuplicates(ListNode head) {
        if (head == null) return null;
        
        HashSet<Integer> seen = new HashSet<>();
        ListNode current = head;
        ListNode previous = null;
        
        while (current != null) {
            if (seen.contains(current.val)) {
                // Duplicate found, remove this node
                previous.next = current.next;
            } else {
                // First time seeing this value
                seen.add(current.val);
                previous = current;
            }
            current = current.next;
        }
        
        return head;
    }
    
    /**
     * Solution 2: Without using additional data structures
     * Time Complexity: O(N²) where N is the length of the linked list
     * Space Complexity: O(1) - no additional data structures used
     */
    public static ListNode removeDuplicatesNoBuffer(ListNode head) {
        if (head == null) return null;
        
        ListNode current = head;
        
        while (current != null) {
            // For each node, check all subsequent nodes for duplicates
            ListNode runner = current;
            while (runner.next != null) {
                if (runner.next.val == current.val) {
                    // Duplicate found, remove the node
                    runner.next = runner.next.next;
                } else {
                    runner = runner.next;
                }
            }
            current = current.next;
        }
        
        return head;
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
        // Test case 1: List with duplicates
        int[] arr1 = {1, 2, 3, 2, 1, 4, 5};
        ListNode list1 = createLinkedList(arr1);
        System.out.print("Original List 1: ");
        printLinkedList(list1);
        
        list1 = removeDuplicates(list1);
        System.out.print("After removing duplicates (using buffer): ");
        printLinkedList(list1);
        
        // Test case 2: List with duplicates (no buffer solution)
        int[] arr2 = {5, 4, 3, 2, 1, 1, 2, 3};
        ListNode list2 = createLinkedList(arr2);
        System.out.print("Original List 2: ");
        printLinkedList(list2);
        
        list2 = removeDuplicatesNoBuffer(list2);
        System.out.print("After removing duplicates (no buffer): ");
        printLinkedList(list2);
        
        // Test case 3: List with no duplicates
        int[] arr3 = {1, 2, 3, 4, 5};
        ListNode list3 = createLinkedList(arr3);
        System.out.print("Original List 3: ");
        printLinkedList(list3);
        
        list3 = removeDuplicates(list3);
        System.out.print("After removing duplicates: ");
        printLinkedList(list3);
    }
}
