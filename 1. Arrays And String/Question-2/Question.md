# String Permutation Check

## Problem Statement

Given two strings, write a code to check if those strings are permutations of each other or not.

A permutation is a rearrangement of letters. For example, "abc" and "cab" are permutations of each other.

## Solutions

### Approach 1: Sorting

We can sort both strings and then compare them. If they are permutations, they will be identical after sorting.

**Time Complexity**: O(n log n) - dominated by the sorting operation
**Space Complexity**: O(n) - for storing the sorted strings

### Approach 2: Character Count

Count the occurrences of each character in both strings. If all character counts match, the strings are permutations.

**Time Complexity**: O(n) - where n is the length of the strings
**Space Complexity**: O(1) or O(c) - where c is the size of the character set (constant for ASCII/Unicode)

## Edge Cases to Consider

- Different length strings cannot be permutations of each other
- Case sensitivity (usually we consider 'A' different from 'a')
- Whitespace handling (depends on requirements)
- Empty strings (are they permutations of each other?)
