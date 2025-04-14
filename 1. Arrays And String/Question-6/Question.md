# String Compression

## Problem Statement

Implement a method to perform basic string compression using the counts of repeated characters. For example, the string "aabcccccaaa" would become "a2b1c5a3". If the "compressed" string would not become smaller than the original string, your method should return the original string.

## Example

Input: "aabcccccaaa"
Output: "a2b1c5a3"

Input: "abcd"
Output: "abcd" (since the compressed version "a1b1c1d1" would be longer)

## Solutions

### Approach: Count Consecutive Characters

Iterate through the string, keeping count of consecutive characters. When the character changes or we reach the end, append the current character and its count to the result.

**Time Complexity**: O(n) where n is the length of the string
**Space Complexity**: O(n) for the compressed string

## Edge Cases to Consider

- Empty strings
- Strings with no repeated characters
- Strings with a single character repeated many times
- Comparing the lengths of original and compressed strings
