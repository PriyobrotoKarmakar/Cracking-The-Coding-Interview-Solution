# Remove Duplicates

## Problem Statement

Write code to remove duplicates from an unsorted linked list.

## Follow Up

How would you solve this problem if a temporary buffer is not allowed?

## Solutions

### Approach 1: Using a Hash Table

Track previously seen elements in a hash table and remove any duplicates.

**Time Complexity**: O(N) where N is the length of the linked list
**Space Complexity**: O(N) to store the hash table

### Approach 2: Without Additional Data Structures

Use two pointers - a current node and a runner through the rest of the list to check for duplicates.

**Time Complexity**: O(N²) where N is the length of the linked list
**Space Complexity**: O(1) as we use no additional data structures

## Edge Cases to Consider

- Empty list
- List with only one element
- List with all duplicates
- List with no duplicates
