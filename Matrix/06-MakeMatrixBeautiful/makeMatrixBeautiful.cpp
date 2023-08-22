// TC : O(N*N) SC : O(N)

#include <bits/stdc++.h>
using namespace std;

    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int N)
    {
        // Initialize vectors to store row and column sums
        vector<int> rowSum;
        vector<int> colSum;
        int maxRowSum = INT_MIN; // Initialize maximum row sum
        int maxColSum = INT_MIN; // Initialize maximum column sum
    
        // Step 1: Calculate the row and column sums, and find the maximum row and column sums
        for (int i = 0; i < N; i++) {
            int rowSumValue = 0;
            int colSumValue = 0;
    
            // Calculate the sum of elements in each row and column
            for (int j = 0; j < N; j++) {
                rowSumValue += matrix[i][j];
                colSumValue += matrix[j][i];
            }
    
            // Store the row and column sums in vectors
            rowSum.push_back(rowSumValue);
            colSum.push_back(colSumValue);
    
            // Update the maximum row and column sums if necessary
            if (rowSumValue > maxRowSum) {
                maxRowSum = rowSumValue;
            }
    
            if (colSumValue > maxColSum) {
                maxColSum = colSumValue;
            }
        }
    
        int totalOperationsNeededForRow = 0;
        int totalOperationsNeededForCol = 0;
    
        // Step 2: Calculate the operations needed for each row and column to reach the maximum sum
        for (int i = 0; i < N; i++) {
            totalOperationsNeededForRow += (maxRowSum - rowSum[i]);
            totalOperationsNeededForCol += (maxColSum - colSum[i]);
        }
    
        // Step 3: Return the maximum of operations needed for rows and columns
        return max(totalOperationsNeededForRow, totalOperationsNeededForCol);
}

int main() {
    // Sample input 1
    int N1 = 3;
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};
    int result1 = findMinOpeartion(matrix1, N1);
    cout << "Sample input 1 result: " << result1 << endl;  // Expected output: 6

    // Sample input 2
    int N2 = 2;
    vector<vector<int>> matrix2 = {{1, 2},
                                    {3, 4}};
    int result2 = findMinOpeartion(matrix2, N2);
    cout << "Sample input 2 result: " << result2 << endl;  // Expected output: 3

    return 0;
}
