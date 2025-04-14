# Zero Matrix

## Problem Statement

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

## Example

Input:

```py
1 2 3
4 0 6
7 8 9
```

Output:

```py
1 0 3
0 0 0
7 0 9
```

## Solutions

### Approach 1: Using Additional Space

Use two arrays to keep track of which rows and columns need to be zeroed out.

**Time Complexity**: O(M×N) where M is the number of rows and N is the number of columns
**Space Complexity**: O(M+N) for storing the zero rows and columns

### Approach 2: Using First Row and Column as Markers

Use the first row and first column to mark which rows and columns need to be zeroed, with special handling for the first row and column themselves.

**Time Complexity**: O(M×N)
**Space Complexity**: O(1) as we use the matrix itself for marking

## Edge Cases to Consider

- Empty matrix
- Matrix with all zeros
- Matrix with no zeros
- Matrix with a single row or column
