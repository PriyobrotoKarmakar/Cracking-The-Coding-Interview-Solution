# Palindrome Permutation

## Problem Statement

Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

## Example

Input: "Tact Coa"
Output: True (permutations: "taco cat", "atco cta", etc.)

## Solutions

### Approach 1: Character Count

Count the occurrences of each character. In a palindrome, at most one character can have an odd count (the middle character).

**Time Complexity**: O(n) where n is the length of the string
**Space Complexity**: O(c) where c is the size of the character set (constant if ASCII)

### Approach 2: Using a Bit Vector

For space optimization, we can use a bit vector to keep track of characters with odd counts.

**Time Complexity**: O(n) where n is the length of the string
**Space Complexity**: O(1) - constant space regardless of input size

## Edge Cases to Consider

- Case sensitivity (usually we ignore case)
- Non-letter characters (usually we ignore spaces, punctuation)
- Empty strings (usually considered palindromes)
