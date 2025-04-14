# Return Kth to Last

## Problem Statement

Implement an algorithm to find the kth to last element of a singly linked list.

## Solutions

### Approach 1: Using Length

First, find the length of the list, then traverse to the (length-k)th element.

**Time Complexity**: O(N) where N is the length of the linked list
**Space Complexity**: O(1) - constant space

### Approach 2: Recursive Approach

Use recursion to traverse to the end of the list and count backward.

**Time Complexity**: O(N)
**Space Complexity**: O(N) due to recursion stack

### Approach 3: Two Pointers

Use two pointers k nodes apart. When the first pointer reaches the end, the second pointer is at the kth to last element.

**Time Complexity**: O(N)
**Space Complexity**: O(1) - constant space

## Edge Cases to Consider

- Empty list
- k is larger than the list length
- k is 0 (last element) or 1 (second to last)
