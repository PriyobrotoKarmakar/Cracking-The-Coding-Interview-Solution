public class Solution {
    /**
     * Solution 1: Using additional arrays to track zero rows and columns
     * Time Complexity: O(M×N) where M is the number of rows and N is the number of columns
     * Space Complexity: O(M+N) for storing the zero rows and columns
     */
    public static void setZeros(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        
        boolean[] zeroRows = new boolean[m];
        boolean[] zeroCols = new boolean[n];
        
        // Mark which rows and columns contain zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        
        // Zero out marked rows
        for (int i = 0; i < m; i++) {
            if (zeroRows[i]) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out marked columns
        for (int j = 0; j < n; j++) {
            if (zeroCols[j]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    /**
     * Solution 2: Using the first row and column as markers
     * Time Complexity: O(M×N)
     * Space Complexity: O(1) as we use the matrix itself for marking
     */
    public static void setZerosOptimized(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        
        // Check if first row has any zeros
        boolean firstRowHasZero = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }
        
        // Check if first column has any zeros
        boolean firstColHasZero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }
        
        // Use first row and column as markers for rest of the matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Zero out rows based on markers in first column
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out columns based on markers in first row
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out first row if needed
        if (firstRowHasZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Zero out first column if needed
        if (firstColHasZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
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
        // Test case 1
        int[][] matrix1 = {
            {1, 2, 3},
            {4, 0, 6},
            {7, 8, 9}
        };
        
        System.out.println("Original Matrix 1:");
        printMatrix(matrix1);
        
        setZeros(matrix1);
        System.out.println("\nZero Matrix 1 (Using additional space):");
        printMatrix(matrix1);
        
        // Test case 2
        int[][] matrix2 = {
            {1, 0, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 0, 12},
            {13, 14, 15, 16}
        };
        
        System.out.println("\nOriginal Matrix 2:");
        printMatrix(matrix2);
        
        setZerosOptimized(matrix2);
        System.out.println("\nZero Matrix 2 (Optimized space):");
        printMatrix(matrix2);
        
        // Test case 3: All zeros
        int[][] matrix3 = {
            {0, 0},
            {0, 0}
        };
        
        System.out.println("\nOriginal Matrix 3:");
        printMatrix(matrix3);
        
        setZeros(matrix3);
        System.out.println("\nZero Matrix 3:");
        printMatrix(matrix3);
        
        // Test case 4: No zeros
        int[][] matrix4 = {
            {1, 1},
            {1, 1}
        };
        
        System.out.println("\nOriginal Matrix 4:");
        printMatrix(matrix4);
        
        setZerosOptimized(matrix4);
        System.out.println("\nZero Matrix 4:");
        printMatrix(matrix4);
    }
}
