# String Rotation

## Problem Statement

Assume you have a method `isSubstring` which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to `isSubstring` (e.g., "waterbottle" is a rotation of "erbottlewat").

## Example

Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True

## Solutions

### Approach: Concatenate the String with Itself

If s2 is a rotation of s1, then s2 must be a substring of s1+s1. For example, if s1="waterbottle" and s2="erbottlewat", then s1+s1="waterbottlewaterbottle" and s2 is a substring of this.

**Time Complexity**: O(N) where N is the length of the strings (assuming isSubstring runs in O(N) time)
**Space Complexity**: O(N) for the concatenated string

## Edge Cases to Consider

- Empty strings
- Strings of different lengths (can't be rotations)
- Identical strings (rotation by 0 positions)
- Case sensitivity
