# Intersection

## Problem Statement

Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

## Solutions

### Approach 1: Using Hash Table

Store the nodes of the first list in a hash table, then check nodes from the second list.

**Time Complexity**: O(N + M) where N and M are the lengths of the two lists
**Space Complexity**: O(N) to store the hash table

### Approach 2: Finding Length Difference

Find the length of both lists, then advance the pointer of the longer list by the difference in lengths. Move both pointers in tandem until they meet.

**Time Complexity**: O(N + M)
**Space Complexity**: O(1) - constant space

## Edge Cases to Consider

- Empty lists
- Lists with no intersection
- Intersection at the beginning, middle, or end
