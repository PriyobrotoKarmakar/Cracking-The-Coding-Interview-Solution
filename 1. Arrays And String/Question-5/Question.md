# One Away

## Problem Statement

There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

## Example

- pale, ple → true (remove 'a')
- pales, pale → true (insert 's')
- pale, bale → true (replace 'p' with 'b')
- pale, bake → false (replace 'p' with 'b', 'l' with 'k')

## Solutions

### Approach: Check Different Edit Types

We can check each possible edit type:

1. Replace: If the strings are the same length, check if they differ by only one character
2. Insert/Remove: If one string is one character longer than the other, check if the longer string has one extra character

**Time Complexity**: O(n) where n is the length of the shorter string
**Space Complexity**: O(1) - constant space regardless of input size

## Edge Cases to Consider

- Empty strings
- Strings of very different lengths (more than 1 character difference)
- Case sensitivity (depends on requirements)
- Identical strings (zero edits)
