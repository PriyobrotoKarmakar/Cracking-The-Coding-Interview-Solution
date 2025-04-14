# Loop Detection

## Problem Statement

Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

Definition: A circular linked list is a corrupt linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

## Example

Input: A->B->C->D->E->C [the same C as earlier]
Output: C

## Solutions

### Approach 1: Hash Table

Track visited nodes in a hash table. The first node visited twice is the start of the loop.

**Time Complexity**: O(N) where N is the length of the linked list
**Space Complexity**: O(N) for the hash table

### Approach 2: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)

Use two pointers, one moving twice as fast as the other. Once they meet, reset one pointer to the head and move both at the same pace until they meet again at the loop start.

**Time Complexity**: O(N)
**Space Complexity**: O(1) - constant space

## Edge Cases to Consider

- Empty list
- List with no loop
- Loop at the beginning or end of the list
