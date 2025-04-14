public class Solution {
    /**
     * Solution: Check if two strings are one edit (or zero edits) away
     * Time Complexity: O(n) where n is the length of the shorter string
     * Space Complexity: O(1) - no extra data structures used
     */
    public static boolean oneEditAway(String first, String second) {
        // If lengths differ by more than 1, return false
        if (Math.abs(first.length() - second.length()) > 1) {
            return false;
        }
        
        // Get shorter and longer string
        String s1 = first.length() <= second.length() ? first : second;
        String s2 = first.length() <= second.length() ? second : first;
        
        int index1 = 0; // Index for shorter string
        int index2 = 0; // Index for longer string
        boolean foundDifference = false;
        
        while (index1 < s1.length() && index2 < s2.length()) {
            if (s1.charAt(index1) != s2.charAt(index2)) {
                // If this is the second difference, return false
                if (foundDifference) {
                    return false;
                }
                foundDifference = true;
                
                // If strings are same length, we're replacing a character
                // Move shorter string pointer only if strings are same length
                if (s1.length() == s2.length()) {
                    index1++;
                }
            } else {
                // If characters match, move shorter string pointer
                index1++;
            }
            // Always move longer string pointer
            index2++;
        }
        
        return true;
    }
    
    /**
     * Alternative solution with separate functions for each edit type
     */
    public static boolean oneEditReplace(String s1, String s2) {
        boolean foundDifference = false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (foundDifference) {
                    return false;
                }
                foundDifference = true;
            }
        }
        return true;
    }
    
    public static boolean oneEditInsert(String s1, String s2) {
        // s1 is shorter, s2 is longer
        int index1 = 0;
        int index2 = 0;
        while (index1 < s1.length() && index2 < s2.length()) {
            if (s1.charAt(index1) != s2.charAt(index2)) {
                if (index1 != index2) {
                    return false;
                }
                index2++;
            } else {
                index1++;
                index2++;
            }
        }
        return true;
    }
    
    public static boolean oneEditAwayAlternative(String first, String second) {
        if (first.length() == second.length()) {
            return oneEditReplace(first, second);
        } else if (first.length() + 1 == second.length()) {
            return oneEditInsert(first, second);
        } else if (first.length() == second.length() + 1) {
            return oneEditInsert(second, first);
        }
        return false;
    }
    
    public static void main(String[] args) {
        String[][] testCases = {
            {"pale", "ple"},     // true - remove 'a'
            {"pales", "pale"},   // true - insert 's'
            {"pale", "bale"},    // true - replace 'p' with 'b'
            {"pale", "bake"},    // false - replace 'p' and 'l'
            {"", ""},            // true - no edits
            {"", "a"},           // true - insert 'a'
            {"abc", "abcd"},     // true - insert 'd'
            {"abc", "abx"},      // true - replace 'c' with 'x'
            {"abc", "xyz"}       // false - multiple changes
        };
        
        System.out.println("Using combined approach:");
        for (String[] test : testCases) {
            System.out.println(test[0] + ", " + test[1] + ": " + 
                              oneEditAway(test[0], test[1]));
        }
        
        System.out.println("\nUsing separate functions approach:");
        for (String[] test : testCases) {
            System.out.println(test[0] + ", " + test[1] + ": " + 
                              oneEditAwayAlternative(test[0], test[1]));
        }
    }
}
