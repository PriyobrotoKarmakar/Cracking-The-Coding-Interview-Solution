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
     * Solution: Copy the data from the next node to the current node, then delete the next node
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     * 
     * Note: This solution assumes that the node to be deleted is not the tail node.
     */
    public static boolean deleteMiddleNode(ListNode node) {
        // Cannot delete last node with this method
        if (node == null || node.next == null) {
            return false;
        }
        
        // Copy data from the next node
        ListNode nextNode = node.next;
        node.val = nextNode.val;
        
        // Delete the next node
        node.next = nextNode.next;
        
        return true;
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
        int[] arr = {1, 2, 3, 4, 5};
        ListNode list = createLinkedList(arr);
        
        System.out.print("Original List: ");
        printLinkedList(list);
        
        // Find the middle node (node with value 3)
        ListNode middleNode = list.next.next; // 3rd node
        
        // Delete the middle node
        if (deleteMiddleNode(middleNode)) {
            System.out.print("After deleting middle node: ");
            printLinkedList(list);
        } else {
            System.out.println("Could not delete the node.");
        }
        
        // Try to delete the last node (should fail)
        ListNode lastNode = list;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }
        
        if (!deleteMiddleNode(lastNode)) {
            System.out.println("As expected, cannot delete the last node using this method.");
        }
        
        // Example from problem statement
        int[] exampleArr = {'a', 'b', 'c', 'd', 'e', 'f'};
        ListNode exampleList = createLinkedList(exampleArr);
        
        System.out.print("\nExample from problem statement - Original: ");
        printLinkedList(exampleList);
        
        // Delete node 'c'
        ListNode nodeC = exampleList.next.next;
        if (deleteMiddleNode(nodeC)) {
            System.out.print("After deleting node 'c': ");
            printLinkedList(exampleList);
        }
    }
}
