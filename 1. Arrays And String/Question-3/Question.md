# URLify

## Problem Statement

Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

## Example

Input: "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"

## Solutions

### Approach: In-place Replacement

We can solve this by working from the back of the string to the front. Since we know the final length of the string, we can place characters in their final positions without overwriting data.

**Time Complexity**: O(n) - where n is the length of the string
**Space Complexity**: O(1) - if we're allowed to modify the input string in-place

## Edge Cases to Consider

- Empty strings
- Strings with only spaces
- Strings with spaces at the beginning or end
- Multiple consecutive spaces
