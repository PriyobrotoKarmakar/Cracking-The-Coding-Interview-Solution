public class Solution {
    /**
     * Solution 1: Using character counting
     * Time Complexity: O(n) where n is the length of the string
     * Space Complexity: O(1) as we use a fixed-size array
     */
    public static boolean isPermutationOfPalindrome(String phrase) {
        int[] table = buildCharFrequencyTable(phrase);
        return checkMaxOneOdd(table);
    }
    
    /* Check that no more than one character has an odd count */
    private static boolean checkMaxOneOdd(int[] table) {
        boolean foundOdd = false;
        for (int count : table) {
            if (count % 2 == 1) {
                if (foundOdd) {
                    return false;
                }
                foundOdd = true;
            }
        }
        return true;
    }
    
    /* Map each character to a number. a -> 0, b -> 1, etc.
     * Non-letter characters map to -1 */
    private static int getCharNumber(Character c) {
        int a = Character.getNumericValue('a');
        int z = Character.getNumericValue('z');
        int val = Character.getNumericValue(c);
        if (a <= val && val <= z) {
            return val - a;
        }
        return -1;
    }
    
    /* Count how many times each character appears */
    private static int[] buildCharFrequencyTable(String phrase) {
        int[] table = new int[26]; // a-z
        for (char c : phrase.toCharArray()) {
            int x = getCharNumber(Character.toLowerCase(c));
            if (x != -1) {
                table[x]++;
            }
        }
        return table;
    }
    
    /**
     * Solution 2: Optimized - Check as we go
     * Time Complexity: O(n) where n is the length of the string
     * Space Complexity: O(1) as we use a fixed-size array
     */
    public static boolean isPermutationOfPalindromeOptimized(String phrase) {
        int countOdd = 0;
        int[] table = new int[26]; // a-z
        for (char c : phrase.toCharArray()) {
            int x = getCharNumber(Character.toLowerCase(c));
            if (x != -1) {
                table[x]++;
                if (table[x] % 2 == 1) {
                    countOdd++;
                } else {
                    countOdd--;
                }
            }
        }
        return countOdd <= 1;
    }
    
    /**
     * Solution 3: Using bit vector
     * Time Complexity: O(n) where n is the length of the string
     * Space Complexity: O(1) as we use only a single integer
     */
    public static boolean isPermutationOfPalindromeBitVector(String phrase) {
        int bitVector = createBitVector(phrase);
        return bitVector == 0 || checkExactlyOneBitSet(bitVector);
    }
    
    /* Create a bit vector for the string. For each letter, toggle the bit */
    private static int createBitVector(String phrase) {
        int bitVector = 0;
        for (char c : phrase.toCharArray()) {
            int x = getCharNumber(Character.toLowerCase(c));
            if (x != -1) {
                bitVector = toggle(bitVector, x);
            }
        }
        return bitVector;
    }
    
    /* Toggle the ith bit in the integer */
    private static int toggle(int bitVector, int index) {
        if (index < 0) return bitVector;
        
        int mask = 1 << index;
        if ((bitVector & mask) == 0) {
            bitVector |= mask;
        } else {
            bitVector &= ~mask;
        }
        return bitVector;
    }
    
    /* Check that exactly one bit is set by subtracting one from the integer and ANDing with the original */
    private static boolean checkExactlyOneBitSet(int bitVector) {
        return (bitVector & (bitVector - 1)) == 0;
    }
    
    public static void main(String[] args) {
        String[] strings = {"Tact Coa", "Race Car", "Was it a cat I saw", "hello", "aab"};
        
        System.out.println("Using character counting method:");
        for (String s : strings) {
            System.out.println(s + ": " + isPermutationOfPalindrome(s));
        }
        
        System.out.println("\nUsing optimized method:");
        for (String s : strings) {
            System.out.println(s + ": " + isPermutationOfPalindromeOptimized(s));
        }
        
        System.out.println("\nUsing bit vector method:");
        for (String s : strings) {
            System.out.println(s + ": " + isPermutationOfPalindromeBitVector(s));
        }
    }
}
