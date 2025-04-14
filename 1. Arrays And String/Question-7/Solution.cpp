#include <iostream>
#include <vector>
using namespace std;

/**
 * Solution 1: Layer by layer rotation
 * Time Complexity: O(n²) where n is the size of the matrix
 * Space Complexity: O(1) as we perform the rotation in-place
 */
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0 || n != matrix[0].size()) {
        // Not a square matrix or empty matrix
        return;
    }
    
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
}

/**
 * Solution 2: Transpose and reverse rows
 * Time Complexity: O(n²)
 * Space Complexity: O(1) as we perform the operations in-place
 */
void rotateMatrixTransposeReverse(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0 || n != matrix[0].size()) {
        // Not a square matrix or empty matrix
        return;
    }
    
    // Transpose the matrix (swap rows and columns)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

// Function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix1);
    
    rotateMatrix(matrix1);
    cout << "\nRotated Matrix 1 (Layer by Layer):" << endl;
    printMatrix(matrix1);
    
    // Test case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    cout << "\nOriginal Matrix 2:" << endl;
    printMatrix(matrix2);
    
    rotateMatrixTransposeReverse(matrix2);
    cout << "\nRotated Matrix 2 (Transpose & Reverse):" << endl;
    printMatrix(matrix2);
    
    // Test case 3: 1x1 matrix
    vector<vector<int>> matrix3 = {{1}};
    
    cout << "\nOriginal Matrix 3:" << endl;
    printMatrix(matrix3);
    
    rotateMatrix(matrix3);
    cout << "\nRotated Matrix 3:" << endl;
    printMatrix(matrix3);
    
    return 0;
}
