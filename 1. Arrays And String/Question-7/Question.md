# Rotate Matrix

## Problem Statement

Given an image represented by an NxN matrix, where each pixel in the image is an integer, write a method to rotate the image by 90 degrees clockwise. Can you do this in-place?

## Example

Input:
```
1 2 3
4 5 6
7 8 9
```

Output (after 90-degree clockwise rotation):
```
7 4 1
8 5 2
9 6 3
```

## Solutions

### Approach 1: Layer-by-Layer Rotation

We can perform the rotation by swapping elements layer by layer from the outermost layer to the innermost layer.

**Time Complexity**: O(n²) where n is the size of the matrix
**Space Complexity**: O(1) as we perform the rotation in-place

### Approach 2: Transpose and Reverse

Another way to rotate a matrix by 90 degrees clockwise is to:

1. Transpose the matrix (swap rows and columns)
2. Reverse each row

**Time Complexity**: O(n²)
**Space Complexity**: O(1) if done in-place

## Edge Cases to Consider

- Empty matrix
- 1x1 matrix (already rotated)
- Non-square matrices (problem specifies NxN, but worth considering)
