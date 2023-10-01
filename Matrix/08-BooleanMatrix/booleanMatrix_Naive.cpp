// Naive Approach
// TC : O(R*C*min(R,C))  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int>>& matrix) {
    int R = matrix.size(); // Get the number of rows in the matrix
    int C = matrix[0].size(); // Get the number of columns in the matrix

    // Step 1: Iterate through the entire matrix
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 1) {
                // Step 2: If a '1' is found in the matrix, mark all elements in the same row as '-1'
                for (int k = 0; k < C; k++) {
                    if (matrix[i][k] != 1) {
                        matrix[i][k] = -1; // Mark as -1 to avoid double modification
                    }
                }

                // Step 3: Mark all elements in the same column as '-1'
                for (int k = 0; k < R; k++) {
                    if (matrix[k][j] != 1) {
                        matrix[k][j] = -1; // Mark as -1 to avoid double modification
                    }
                }
            }
        }
    }

    // Step 4: Replace all '-1' with '1'
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1; // Replace '-1' with '1'
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
