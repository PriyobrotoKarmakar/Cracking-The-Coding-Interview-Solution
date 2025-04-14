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
     * Solution 1: Creating two separate lists and merging them
     * Time Complexity: O(N) where N is the length of the linked list
     * Space Complexity: O(1) as we're just rearranging pointers
     */
    public static ListNode partition(ListNode head, int x) {
        if (head == null) return null;
        
        ListNode beforeStart = null;
        ListNode beforeEnd = null;
        ListNode afterStart = null;
        ListNode afterEnd = null;
        
        // Partition list
        while (head != null) {
            ListNode next = head.next;
            head.next = null;
            
            if (head.val < x) {
                // Insert node into end of before list
                if (beforeStart == null) {
                    beforeStart = head;
                    beforeEnd = head;
                } else {
                    beforeEnd.next = head;
                    beforeEnd = head;
                }
            } else {
                // Insert node into end of after list
                if (afterStart == null) {
                    afterStart = head;
                    afterEnd = head;
                } else {
                    afterEnd.next = head;
                    afterEnd = head;
                }
            }
            
            head = next;
        }
        
        // If there's no "before" list, return the "after" list
        if (beforeStart == null) {
            return afterStart;
        }
        
        // Merge the two lists
        beforeEnd.next = afterStart;
        
        return beforeStart;
    }
    
    /**
     * Solution 2: Creating a new list by inserting elements at the beginning or end
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    public static ListNode partitionAlternative(ListNode head, int x) {
        if (head == null) return null;
        
        ListNode dummy = new ListNode(0); // Dummy head to simplify code
        dummy.next = head;
        
        ListNode tail = head; // Points to the last node in the list
        
        // Find the tail node
        while (tail.next != null) {
            tail = tail.next;
        }
        
        ListNode end = tail; // The current end of our processed list
        
        // Start processing from the head
        ListNode current = head;
        ListNode prev = dummy;
        
        while (current != end.next) {
            ListNode next = current.next;
            
            if (current.val >= x) {
                // Move to the end of the list
                prev.next = next;
                end.next = current;
                current.next = null;
                end = current;
            } else {
                // Keep in place
                prev = current;
            }
            
            current = next;
        }
        
        return dummy.next;
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
        // Example from the problem statement
        int[] arr = {3, 5, 8, 5, 10, 2, 1};
        ListNode list = createLinkedList(arr);
        
        System.out.print("Original List: ");
        printLinkedList(list);
        
        int partition = 5;
        System.out.println("Partition value: " + partition);
        
        ListNode partitioned = partition(list, partition);
        System.out.print("After partitioning (Solution 1): ");
        printLinkedList(partitioned);
        
        // Test with alternative solution
        list = createLinkedList(arr); // Recreate the list
        ListNode partitioned2 = partitionAlternative(list, partition);
        System.out.print("After partitioning (Solution 2): ");
        printLinkedList(partitioned2);
        
        // Test edge cases
        
        // 1. All elements less than partition value
        int[] arr2 = {1, 2, 3, 4};
        list = createLinkedList(arr2);
        System.out.print("\nAll elements less than partition: ");
        printLinkedList(list);
        
        partitioned = partition(list, 5);
        System.out.print("After partitioning: ");
        printLinkedList(partitioned);
        
        // 2. All elements greater than or equal to partition value
        int[] arr3 = {5, 6, 7, 8};
        list = createLinkedList(arr3);
        System.out.print("\nAll elements greater than partition: ");
        printLinkedList(list);
        
        partitioned = partition(list, 5);
        System.out.print("After partitioning: ");
        printLinkedList(partitioned);
        
        // 3. Empty list
        System.out.print("\nEmpty list partitioning: ");
        partitioned = partition(null, 5);
        printLinkedList(partitioned);
    }
}
