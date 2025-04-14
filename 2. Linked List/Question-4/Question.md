# Partition

## Problem Statement

Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

## Example

Input: 3->5->8->5->10->2->1 [partition=5]
Output: 3->1->2->10->5->5->8

## Solutions

### Approach 1: Two Separate Lists

Create two separate linked lists, one for elements less than x and one for elements greater than or equal to x, then merge them.

**Time Complexity**: O(N) where N is the length of the linked list
**Space Complexity**: O(1) - we're rearranging existing nodes

### Approach 2: Single Pass with Two Pointers

Maintain two pointers, one at the tail of the "less than x" section and one traversing the list.

**Time Complexity**: O(N)
**Space Complexity**: O(1)

## Edge Cases to Consider

- Empty list
- List with only one element
- No elements less than x
- All elements less than x
