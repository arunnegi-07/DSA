// Optimized Approach
// TC : O(R*C)  SC : O(R+C)

#include <bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Get the number of rows in the matrix
    int m = matrix[0].size(); // Get the number of columns in the matrix

    // Step 1: Create arrays to store coordinates of cells having '1' in rows and columns
    int row[n], col[m];

    // Initialize row and col arrays to false values
    for (int i = 0; i < n; i++) {
        row[i] = false;
    }
    for (int j = 0; j < m; j++) {
        col[j] = false;
    }

    // Step 2: Traverse the matrix to mark rows and columns with '1'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                row[i] = true; // Mark the row as having '1'
                col[j] = true; // Mark the column as having '1'
            }
        }
    }

    // Step 3: Iterate through the matrix again and modify cells with '0'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0 && (row[i] == true || col[j] == true)) {
                // If the cell is '0' and its row or column has '1', set it to '1'
                matrix[i][j] = 1;
            }
        }
    }
}


int main() {
    // Sample input 1
    int R1 = 2, C1 = 2;
    vector<vector<int>> matrix1 = {{1, 0}, {0, 0}};

    cout << "Sample Input 1:" << endl;
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    booleanMatrix(matrix1);

    cout << "Modified Matrix 1:" << endl;
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    // Sample input 2
    int R2 = 4, C2 = 3;
    vector<vector<int>> matrix2 = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {0, 0, 0}};

    cout << "Sample Input 2:" << endl;
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    booleanMatrix(matrix2);

    cout << "Modified Matrix 2:" << endl;
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
