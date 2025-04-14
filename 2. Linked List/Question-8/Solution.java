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
     * Floyd's Cycle Detection Algorithm (Tortoise and Hare)
     * Time Complexity: O(N) where N is the length of the linked list
     * Space Complexity: O(1)
     */
    public static ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        
        // Phase 1: Detect if there is a cycle
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;           // Move slow pointer by 1 step
            fast = fast.next.next;      // Move fast pointer by 2 steps
            
            if (slow == fast) {  // Cycle detected
                break;
            }
        }
        
        // Check if we found a cycle
        if (fast == null || fast.next == null) {
            return null;  // No cycle
        }
        
        // Phase 2: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        
        return slow;  // Start of the cycle
    }
    
    /**
     * Alternative approach using a hash set (not optimized for space)
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    public static ListNode detectCycleWithHashSet(ListNode head) {
        java.util.Set<ListNode> visited = new java.util.HashSet<>();
        
        ListNode current = head;
        while (current != null) {
            if (visited.contains(current)) {
                return current;  // Found the cycle start
            }
            
            visited.add(current);
            current = current.next;
        }
        
        return null;  // No cycle
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
    
    // Helper function to print a linked list (avoiding cycles)
    public static void printLinkedList(ListNode head, int maxNodes) {
        int count = 0;
        while (head != null && count < maxNodes) {
            System.out.print(head.val);
            if (head.next != null && count < maxNodes - 1) {
                System.out.print(" -> ");
            }
            head = head.next;
            count++;
        }
        
        if (head != null) {
            System.out.print(" -> ... (more nodes)");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        // Test case 1: Create a list with a cycle: 1->2->3->4->5->3
        ListNode list1 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        ListNode tail = list1;
        while (tail.next != null) {
            tail = tail.next;
        }
        
        // Node to connect to (3rd node, value 3)
        ListNode cycleStart = list1.next.next;
        tail.next = cycleStart;  // Create cycle
        
        System.out.println("List with cycle (showing first few nodes):");
        printLinkedList(list1, 8);
        System.out.println("Cycle starts at node with value: " + cycleStart.val);
        
        // Detect cycle using both methods
        ListNode detected1 = detectCycle(list1);
        ListNode detected2 = detectCycleWithHashSet(list1);
        
        System.out.println("Detected cycle start (Method 1): " + 
                          (detected1 != null ? detected1.val : "None"));
        System.out.println("Detected cycle start (Method 2): " + 
                          (detected2 != null ? detected2.val : "None"));
        
        // Test case 2: No cycle
        ListNode list2 = createLinkedList(new int[]{1, 2, 3, 4, 5});
        
        System.out.println("\nList without cycle:");
        printLinkedList(list2, 10);
        
        detected1 = detectCycle(list2);
        detected2 = detectCycleWithHashSet(list2);
        
        System.out.println("Detected cycle start (Method 1): " + 
                          (detected1 != null ? detected1.val : "None"));
        System.out.println("Detected cycle start (Method 2): " + 
                          (detected2 != null ? detected2.val : "None"));
        
        // Test case 3: Cycle at the beginning (1->1)
        ListNode list3 = new ListNode(1);
        list3.next = list3;  // Points to itself
        
        System.out.println("\nList with self-cycle:");
        System.out.println("1 -> 1 -> ...");
        
        detected1 = detectCycle(list3);
        detected2 = detectCycleWithHashSet(list3);
        
        System.out.println("Detected cycle start (Method 1): " + 
                          (detected1 != null ? detected1.val : "None"));
        System.out.println("Detected cycle start (Method 2): " + 
                          (detected2 != null ? detected2.val : "None"));
        
        // Test case 4: Empty list
        System.out.println("\nEmpty list:");
        detected1 = detectCycle(null);
        
        System.out.println("Detected cycle start: " + 
                          (detected1 != null ? detected1.val : "None"));
    }
}
