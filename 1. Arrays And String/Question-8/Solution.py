#!/usr/bin/env python3

def set_zeros(matrix):
    """
    Solution 1: Using additional arrays to track zero rows and columns
    Time Complexity: O(M×N) where M is the number of rows and N is the number of columns
    Space Complexity: O(M+N) for storing the zero rows and columns
    
    Modifies the matrix in-place.
    """
    if not matrix or not matrix[0]:
        return
    
    m = len(matrix)
    n = len(matrix[0])
    
    # Track which rows and columns have zeros
    zero_rows = [False] * m
    zero_cols = [False] * n
    
    # Mark which rows and columns contain zeros
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                zero_rows[i] = True
                zero_cols[j] = True
    
    # Zero out marked rows
    for i in range(m):
        if zero_rows[i]:
            for j in range(n):
                matrix[i][j] = 0
    
    # Zero out marked columns
    for j in range(n):
        if zero_cols[j]:
            for i in range(m):
                matrix[i][j] = 0

def set_zeros_optimized(matrix):
    """
    Solution 2: Using the first row and column as markers
    Time Complexity: O(M×N)
    Space Complexity: O(1) as we use the matrix itself for marking
    
    Modifies the matrix in-place.
    """
    if not matrix or not matrix[0]:
        return
    
    m = len(matrix)
    n = len(matrix[0])
    
    # Check if first row has any zeros
    first_row_has_zero = False
    for j in range(n):
        if matrix[0][j] == 0:
            first_row_has_zero = True
            break
    
    # Check if first column has any zeros
    first_col_has_zero = False
    for i in range(m):
        if matrix[i][0] == 0:
            first_col_has_zero = True
            break
    
    # Use first row and column as markers for rest of the matrix
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    
    # Zero out rows based on markers in first column
    for i in range(1, m):
        if matrix[i][0] == 0:
            for j in range(1, n):
                matrix[i][j] = 0
    
    # Zero out columns based on markers in first row
    for j in range(1, n):
        if matrix[0][j] == 0:
            for i in range(1, m):
                matrix[i][j] = 0
    
    # Zero out first row if needed
    if first_row_has_zero:
        for j in range(n):
            matrix[0][j] = 0
    
    # Zero out first column if needed
    if first_col_has_zero:
        for i in range(m):
            matrix[i][0] = 0

def print_matrix(matrix):
    """Helper function to print matrix in a readable format"""
    for row in matrix:
        print(' '.join(str(val) for val in row))

if __name__ == "__main__":
    # Test case 1
    matrix1 = [
        [1, 2, 3],
        [4, 0, 6],
        [7, 8, 9]
    ]
    
    print("Original Matrix 1:")
    print_matrix(matrix1)
    
    set_zeros(matrix1)
    print("\nZero Matrix 1 (Using additional space):")
    print_matrix(matrix1)
    
    # Test case 2
    matrix2 = [
        [1, 0, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 0, 12],
        [13, 14, 15, 16]
    ]
    
    print("\nOriginal Matrix 2:")
    print_matrix(matrix2)
    
    set_zeros_optimized(matrix2)
    print("\nZero Matrix 2 (Optimized space):")
    print_matrix(matrix2)
    
    # Test case 3: All zeros
    matrix3 = [
        [0, 0],
        [0, 0]
    ]
    
    print("\nOriginal Matrix 3:")
    print_matrix(matrix3)
    
    set_zeros(matrix3)
    print("\nZero Matrix 3:")
    print_matrix(matrix3)
    
    # Test case 4: No zeros
    matrix4 = [
        [1, 1],
        [1, 1]
    ]
    
    print("\nOriginal Matrix 4:")
    print_matrix(matrix4)
    
    set_zeros_optimized(matrix4)
    print("\nZero Matrix 4:")
    print_matrix(matrix4)
