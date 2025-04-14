public class Solution {
    /**
     * Solution 1: Layer by layer rotation
     * Time Complexity: O(n²) where n is the size of the matrix
     * Space Complexity: O(1) as we perform the rotation in-place
     */
    public static boolean rotateMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix.length != matrix[0].length) {
            // Not a square matrix or empty matrix
            return false;
        }
        
        int n = matrix.length;
        
        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            
            for (int i = first; i < last; i++) {
                int offset = i - first;
                
                // Save top
                int top = matrix[first][i];
                
                // Left -> Top
                matrix[first][i] = matrix[last - offset][first];
                
                // Bottom -> Left
                matrix[last - offset][first] = matrix[last][last - offset];
                
                // Right -> Bottom
                matrix[last][last - offset] = matrix[i][last];
                
                // Top -> Right
                matrix[i][last] = top;
            }
        }
        
        return true;
    }
    
    /**
     * Solution 2: Transpose and reverse rows
     * Time Complexity: O(n²)
     * Space Complexity: O(1) as we perform the operations in-place
     */
    public static boolean rotateMatrixTransposeReverse(int[][] matrix) {
        if (matrix.length == 0 || matrix.length != matrix[0].length) {
            // Not a square matrix or empty matrix
            return false;
        }
        
        int n = matrix.length;
        
        // Transpose the matrix (swap rows and columns)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
        
        return true;
    }
    
    // Function to print matrix
    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        // Test case 1: 3x3 matrix
        int[][] matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("Original Matrix 1:");
        printMatrix(matrix1);
        
        rotateMatrix(matrix1);
        System.out.println("\nRotated Matrix 1 (Layer by Layer):");
        printMatrix(matrix1);
        
        // Test case 2: 4x4 matrix
        int[][] matrix2 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        
        System.out.println("\nOriginal Matrix 2:");
        printMatrix(matrix2);
        
        rotateMatrixTransposeReverse(matrix2);
        System.out.println("\nRotated Matrix 2 (Transpose & Reverse):");
        printMatrix(matrix2);
        
        // Test case 3: 1x1 matrix
        int[][] matrix3 = {{1}};
        
        System.out.println("\nOriginal Matrix 3:");
        printMatrix(matrix3);
        
        rotateMatrix(matrix3);
        System.out.println("\nRotated Matrix 3:");
        printMatrix(matrix3);
    }
}
