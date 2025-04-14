


def rotate_matrix(matrix):
    """
    Solution 1: Layer by layer rotation
    Time Complexity: O(n²) where n is the size of the matrix
    Space Complexity: O(1) as we perform the rotation in-place
    
    Returns True if rotation was successful, False otherwise
    """
    if not matrix or len(matrix) == 0 or len(matrix) != len(matrix[0]):
        # Not a square matrix or empty matrix
        return False
    
    n = len(matrix)
    
    for layer in range(n // 2):
        first = layer
        last = n - 1 - layer
        
        for i in range(first, last):
            offset = i - first
            
            # Save top
            top = matrix[first][i]
            
            # Left -> Top
            matrix[first][i] = matrix[last - offset][first]
            
            # Bottom -> Left
            matrix[last - offset][first] = matrix[last][last - offset]
            
            # Right -> Bottom
            matrix[last][last - offset] = matrix[i][last]
            
            # Top -> Right
            matrix[i][last] = top
    
    return True

def rotate_matrix_transpose_reverse(matrix):
    """
    Solution 2: Transpose and reverse rows
    Time Complexity: O(n²)
    Space Complexity: O(1) as we perform the operations in-place
    
    Returns True if rotation was successful, False otherwise
    """
    if not matrix or len(matrix) == 0 or len(matrix) != len(matrix[0]):
        # Not a square matrix or empty matrix
        return False
    
    n = len(matrix)
    
    # Transpose the matrix (swap rows and columns)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
    # Reverse each row
    for i in range(n):
        matrix[i].reverse()
    
    return True

def rotate_matrix_pythonic(matrix):
    """
    Solution 3: Pythonic approach using list comprehensions
    Time Complexity: O(n²)
    Space Complexity: O(n²) as we create a new matrix
    
    Returns a new rotated matrix or None if input is invalid
    """
    if not matrix or len(matrix) == 0 or len(matrix) != len(matrix[0]):
        # Not a square matrix or empty matrix
        return None
    
    n = len(matrix)
    # Create a new rotated matrix using list comprehension
    # For each row in the output matrix, we take the corresponding column from the input
    # but in reverse order (bottom to top)
    return [[matrix[n - 1 - j][i] for j in range(n)] for i in range(n)]

def print_matrix(matrix):
    """Helper function to print matrix in a readable format"""
    for row in matrix:
        print(' '.join(str(val) for val in row))

if __name__ == "__main__":
    # Test case 1: 3x3 matrix
    matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    
    print("Original Matrix 1:")
    print_matrix(matrix1)
    
    rotate_matrix(matrix1)
    print("\nRotated Matrix 1 (Layer by Layer):")
    print_matrix(matrix1)
    
    # Test case 2: 4x4 matrix
    matrix2 = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
    
    print("\nOriginal Matrix 2:")
    print_matrix(matrix2)
    
    rotate_matrix_transpose_reverse(matrix2)
    print("\nRotated Matrix 2 (Transpose & Reverse):")
    print_matrix(matrix2)
    
    # Test case 3: Using the Pythonic approach
    matrix3 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    
    print("\nOriginal Matrix 3:")
    print_matrix(matrix3)
    
    rotated3 = rotate_matrix_pythonic(matrix3)
    print("\nRotated Matrix 3 (Pythonic approach):")
    print_matrix(rotated3)
    
    # Test case 4: 1x1 matrix
    matrix4 = [[1]]
    
    print("\nOriginal Matrix 4:")
    print_matrix(matrix4)
    
    rotate_matrix(matrix4)
    print("\nRotated Matrix 4:")
    print_matrix(matrix4)
