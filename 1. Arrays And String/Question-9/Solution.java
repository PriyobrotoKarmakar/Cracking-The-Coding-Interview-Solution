public class Solution {
    /**
     * Utility method to check if one string is a substring of another
     * This simulates the isSubstring method that we're asked to assume exists
     */
    public static boolean isSubstring(String s1, String s2) {
        return s1.contains(s2);
    }
    
    /**
     * Solution: Check if s2 is a rotation of s1
     * Time Complexity: O(N) where N is the length of the strings (assuming isSubstring runs in O(N) time)
     * Space Complexity: O(N) for the concatenated string
     */
    public static boolean isRotation(String s1, String s2) {
        // Check if the strings have the same length and are not empty
        if (s1.length() != s2.length() || s1.length() == 0) {
            return false;
        }
        
        // Concatenate s1 with itself
        String s1s1 = s1 + s1;
        
        // Check if s2 is a substring of s1s1
        return isSubstring(s1s1, s2);
    }
    
    public static void main(String[] args) {
        String[][] testCases = {
            {"waterbottle", "erbottlewat"},  // True - rotation
            {"abcde", "cdeab"},              // True - rotation
            {"abcde", "abcde"},              // True - rotation by 0 positions
            {"abcde", "edcba"},              // False - not a rotation, but reversed
            {"abcde", "abcdef"},             // False - different lengths
            {"", ""},                        // False - empty strings
            {"a", "a"}                       // True - single character
        };
        
        for (String[] test : testCases) {
            String s1 = test[0];
            String s2 = test[1];
            boolean result = isRotation(s1, s2);
            
            System.out.println("Is \"" + s2 + "\" a rotation of \"" + s1 + "\"? " 
                               + (result ? "Yes" : "No"));
        }
    }
}
