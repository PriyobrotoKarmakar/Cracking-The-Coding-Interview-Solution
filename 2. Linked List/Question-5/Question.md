# Sum Lists

## Problem Statement

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

## Example

Input: (7->1->6) + (5->9->2). That is, 617 + 295.
Output: 2->1->9. That is, 912.

## Follow Up

Suppose the digits are stored in forward order. Repeat the above problem.

Input: (6->1->7) + (2->9->5). That is, 617 + 295.
Output: 9->1->2. That is, 912.

## Solutions

### Approach 1: Iterative

Traverse both lists simultaneously, adding digits and keeping track of carry.

**Time Complexity**: O(max(N, M)) where N and M are the lengths of the two lists
**Space Complexity**: O(max(N, M)) for the result list

### Approach 2: Recursive

Recursively add corresponding nodes, passing the carry upward.

**Time Complexity**: O(max(N, M))
**Space Complexity**: O(max(N, M)) due to recursion stack

## Edge Cases to Consider

- Lists of different lengths
- Carry in the most significant place (requiring an extra node)
- Empty lists
