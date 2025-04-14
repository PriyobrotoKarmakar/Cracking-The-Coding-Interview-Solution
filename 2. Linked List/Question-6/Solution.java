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
     * Solution 1: Reverse and Compare
     * Time Complexity: O(N) where N is the length of the linked list
     * Space Complexity: O(N) for creating the reversed list
     */
    public static boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        
        // Create a reversed copy of the list
        ListNode reversed = reverseAndClone(head);
        
        // Compare the original and reversed lists
        return isEqual(head, reversed);
    }
    
    private static ListNode reverseAndClone(ListNode node) {
        ListNode head = null;
        
        while (node != null) {
            ListNode newNode = new ListNode(node.val);
            newNode.next = head;
            head = newNode;
            node = node.next;
        }
        
        return head;
    }
    
    private static boolean isEqual(ListNode l1, ListNode l2) {
        while (l1 != null && l2 != null) {
            if (l1.val != l2.val) {
                return false;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        
        return l1 == null && l2 == null;
    }
    
    /**
     * Solution 2: Runner Technique (Fast and Slow Pointers)
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    public static boolean isPalindromeOptimized(ListNode head) {
        if (head == null || head.next == null) return true;
        
        // Find the middle of the linked list using fast/slow runners
        ListNode slow = head;
        ListNode fast = head;
        
        // Move fast runner twice as fast as slow runner
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // If list has odd number of elements, skip the middle element
        if (fast != null) {
            slow = slow.next;
        }
        
        // Reverse the second half of the list
        ListNode secondHalf = reverse(slow);
        ListNode firstHalf = head;
        
        // Compare the first and second half
        while (secondHalf != null) {
            if (firstHalf.val != secondHalf.val) {
                return false;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }
        
        return true;
    }
    
    private static ListNode reverse(ListNode head) {
        ListNode prev = null;
        
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
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
        // Test cases for palindromic lists
        int[][] palindromeArrays = {
            {1, 2, 1},
            {1, 2, 2, 1},
            {1, 2, 3, 2, 1},
            {1}
        };
        
        System.out.println("Testing palindromic lists:");
        for (int[] arr : palindromeArrays) {
            ListNode list = createLinkedList(arr);
            System.out.print("List: ");
            printLinkedList(list);
            
            boolean isPalindrome1 = isPalindrome(list);
            boolean isPalindrome2 = isPalindromeOptimized(list);
            
            System.out.println("Is palindrome (Solution 1): " + isPalindrome1);
            System.out.println("Is palindrome (Solution 2): " + isPalindrome2);
            System.out.println();
        }
        
        // Test cases for non-palindromic lists
        int[][] nonPalindromeArrays = {
            {1, 2, 3},
            {1, 2, 3, 4},
            {1, 2, 3, 4, 5, 6}
        };
        
        System.out.println("Testing non-palindromic lists:");
        for (int[] arr : nonPalindromeArrays) {
            ListNode list = createLinkedList(arr);
            System.out.print("List: ");
            printLinkedList(list);
            
            boolean isPalindrome1 = isPalindrome(list);
            boolean isPalindrome2 = isPalindromeOptimized(list);
            
            System.out.println("Is palindrome (Solution 1): " + isPalindrome1);
            System.out.println("Is palindrome (Solution 2): " + isPalindrome2);
            System.out.println();
        }
        
        // Edge case: empty list
        System.out.println("Edge case - Empty list:");
        boolean isPalindrome1 = isPalindrome(null);
        boolean isPalindrome2 = isPalindromeOptimized(null);
        
        System.out.println("Is palindrome (Solution 1): " + isPalindrome1);
        System.out.println("Is palindrome (Solution 2): " + isPalindrome2);
    }
}
