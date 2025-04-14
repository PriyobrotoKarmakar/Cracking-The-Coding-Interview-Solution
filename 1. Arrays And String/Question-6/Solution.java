public class Solution {
    /**
     * Solution 1: Using StringBuilder to build compressed string
     * Time Complexity: O(n) where n is the length of the string
     * Space Complexity: O(n) for the compressed string
     */
    public static String compressString(String str) {
        if (str == null || str.length() <= 1) {
            return str;
        }
        
        StringBuilder compressed = new StringBuilder();
        int countConsecutive = 1;
        
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == str.charAt(i - 1)) {
                countConsecutive++;
            } else {
                compressed.append(str.charAt(i - 1));
                compressed.append(countConsecutive);
                countConsecutive = 1;
            }
        }
        
        // Add last character and its count
        compressed.append(str.charAt(str.length() - 1));
        compressed.append(countConsecutive);
        
        // Return the shorter string
        return compressed.length() < str.length() ? compressed.toString() : str;
    }
    
    /**
     * Solution 2: Calculate final length first to avoid unnecessary work
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String compressStringOptimized(String str) {
        // Check if compression would save space
        int compressedLength = countCompression(str);
        if (compressedLength >= str.length()) {
            return str;
        }
        
        StringBuilder compressed = new StringBuilder(compressedLength); // Pre-allocate space
        int countConsecutive = 1;
        
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == str.charAt(i - 1)) {
                countConsecutive++;
            } else {
                compressed.append(str.charAt(i - 1));
                compressed.append(countConsecutive);
                countConsecutive = 1;
            }
        }
        
        // Add last character and its count
        compressed.append(str.charAt(str.length() - 1));
        compressed.append(countConsecutive);
        
        return compressed.toString();
    }
    
    /**
     * Helper function to count the length of the compressed string
     */
    private static int countCompression(String str) {
        if (str == null || str.isEmpty()) {
            return 0;
        }
        
        int compressedLength = 0;
        int countConsecutive = 1;
        
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == str.charAt(i - 1)) {
                countConsecutive++;
            } else {
                compressedLength += 1 + String.valueOf(countConsecutive).length();
                countConsecutive = 1;
            }
        }
        
        // Add last character and its count
        compressedLength += 1 + String.valueOf(countConsecutive).length();
        
        return compressedLength;
    }
    
    /**
     * Solution 3: Character-by-character approach with StringBuilder
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String compressStringCharByChar(String str) {
        if (str == null || str.length() <= 1) {
            return str;
        }
        
        StringBuilder compressed = new StringBuilder();
        char[] chars = str.toCharArray();
        
        char currentChar = chars[0];
        int count = 1;
        
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == currentChar) {
                count++;
            } else {
                compressed.append(currentChar).append(count);
                currentChar = chars[i];
                count = 1;
            }
        }
        
        // Don't forget the last run of characters
        compressed.append(currentChar).append(count);
        
        return compressed.length() < str.length() ? compressed.toString() : str;
    }
    
    public static void main(String[] args) {
        String[] testCases = {
            "aabcccccaaa",  // should compress to "a2b1c5a3"
            "abcd",         // should stay "abcd"
            "aabb",         // should stay "aabb" (since "a2b2" is same length)
            "aaa",          // should compress to "a3"
            "a",            // should stay "a"
            ""              // should stay ""
        };
        
        System.out.println("Using StringBuilder approach:");
        for (String test : testCases) {
            System.out.println("\"" + test + "\" -> \"" + compressString(test) + "\"");
        }
        
        System.out.println("\nUsing optimized approach:");
        for (String test : testCases) {
            System.out.println("\"" + test + "\" -> \"" + compressStringOptimized(test) + "\"");
        }
        
        System.out.println("\nUsing char-by-char approach:");
        for (String test : testCases) {
            System.out.println("\"" + test + "\" -> \"" + compressStringCharByChar(test) + "\"");
        }
    }
}
