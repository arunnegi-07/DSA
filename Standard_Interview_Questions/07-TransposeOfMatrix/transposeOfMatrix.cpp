/* TC : O(N*N)  SC :  O(1)
    Just have to swap values of matrix[i][j] and matrix[j][i], make sure to do swap values for either i < j (or) i > j
    because if we swap for all 'i' and 'j' then we will get the same matrix back so we just have to do swapping
    for half of the values only, then it will result in transpose of matrix.
                                                                                                                                                                                                                                                                                    */

#include <bits/stdc++.h>
using namespace std;

// Function to find the transpose of a matrix
void transpose(vector<vector<int>>& matrix, int n)
{
    // Iterate through each row
    for (int i = 0; i < n; i++) {
        // Iterate through each column
        for (int j = 0; j < n; j++) {
            // Swap the elements if i < j
            if (i < j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    // Sample Input 1
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    int n1 = matrix1.size();

    // Find the transpose of matrix1
    transpose(matrix1, n1);

    // Display the transpose
    cout << "Transpose of matrix1:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    // Sample Input 2
    vector<vector<int>> matrix2 = {{1, 2},
                                   {3, 4}};
    int n2 = matrix2.size();

    // Find the transpose of matrix2
    transpose(matrix2, n2);

    // Display the transpose
    cout << "Transpose of matrix2:" << endl;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
