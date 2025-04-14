# Delete Middle Node

## Problem Statement

Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

## Example

Input: the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f

## Solutions

### Approach: Copy Next Node

Copy the data from the next node to the current node, then delete the next node.

**Time Complexity**: O(1)
**Space Complexity**: O(1)

## Edge Cases to Consider

- Node is the last node (cannot be deleted with this method)
- Node is NULL
