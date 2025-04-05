# Question 1: Is Unique

## Problem Statement
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

## Solution Approach

### Approach 1: Using Additional Data Structure (Hash Table/Array)
We can use a boolean array or hash table to keep track of characters we've seen. When we encounter a character, we check if it's already in our data structure. If it is, the string has duplicate characters. If not, we mark it as seen and continue.

**Time Complexity**: O(n) where n is the length of the string. We need to iterate through each character once.
**Space Complexity**: O(c) where c is the size of the character set. For ASCII, this is O(128), which is constant space.

### Approach 2: Using Bit Vector (for lowercase a-z only)
If we're restricted to just lowercase letters a-z, we can use a bit vector (a single integer) to keep track of which characters we've seen. Each bit represents one character. This reduces our space usage to just one integer (32 bits).

**Time Complexity**: O(n) where n is the length of the string.
**Space Complexity**: O(1) - constant space as we only use a single integer.

### Approach 3: Without Additional Data Structures
If we cannot use any additional data structures, we can compare every character of the string with every other character. This brute force approach doesn't require extra space.

**Time Complexity**: O(n²) where n is the length of the string, as we need to compare each character with all others.
**Space Complexity**: O(1) - constant space as we don't use any additional data structures.

### Optimizations
- We can immediately return false if the string length exceeds the size of the character set (e.g., 128 for ASCII, 26 for lowercase letters), as there must be duplicates in that case.
- For very large strings, sorting the string first (in O(n log n) time) and then checking for adjacent duplicates might be more efficient than the brute force O(n²) approach when no additional data structures are allowed.