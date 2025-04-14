# Palindrome

## Problem Statement

Implement a function to check if a linked list is a palindrome.

## Example

Input: 1->2->2->1
Output: true (it reads the same forward and backward)

Input: 1->2->3->2->1
Output: true

Input: 1->2->3->4
Output: false

## Solutions

### Approach 1: Reverse and Compare

Reverse the linked list and compare it with the original list.

**Time Complexity**: O(N) where N is the length of the linked list
**Space Complexity**: O(N) for the reversed list

### Approach 2: Stack

Push the first half of the elements onto a stack, then compare with the second half.

**Time Complexity**: O(N)
**Space Complexity**: O(N/2) ≈ O(N)

### Approach 3: Recursive

Use recursion to compare the first and last elements, then move inward.

**Time Complexity**: O(N)
**Space Complexity**: O(N) due to recursion stack

## Edge Cases to Consider

- Empty list
- List with a single element
- Even vs. odd number of elements
