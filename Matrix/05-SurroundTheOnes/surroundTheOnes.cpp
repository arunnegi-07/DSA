/* TC : O(N*N)  SC : O(1)
   Problem is very simple, we just have to check in all 8 directions for every '1' present and the matrix and
   add it to our answer if it is surrounded by even 0's.
                                                                                                                                            */

#include <bits/stdc++.h>
using namespace std;

int Count(vector<vector<int> >& matrix) {
    int i = matrix.size();  // Get the number of rows in the matrix
    int j = matrix[0].size();  // Get the number of columns in the matrix

    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};  // Array for horizontal directions
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};  // Array for vertical directions

    int ans = 0;  // Initialize a counter for the result

    // Loop through each cell in the matrix
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            int countZero = 0;  // Initialize a count for surrounding 0's

            // Check each of the 8 surrounding cells
            for (int x = 0; x < 8; x++) {
                int drow = row + dx[x];  // Calculate the row index of the surrounding cell
                int dcol = col + dy[x];  // Calculate the column index of the surrounding cell

                // Check if the surrounding cell is within bounds and contains a 0
                // Also, check if the current cell contains a 1
                if (drow >= 0 && drow < i && dcol >= 0 && dcol < j && matrix[row][col] == 1 && matrix[drow][dcol] == 0) {
                    countZero++;  // Increment the count of surrounding 0's
                }
            }

            // If the count of surrounding 0's is even and not equal to 0, increment the answer counter
            if (!(countZero % 2) && countZero != 0) {
                ans++;
            }
        }
    }

    return ans;  // Return the final count of 1's surrounded by an even number of 0's
}


int main() {
    // Sample input 1
    vector<vector<int>> matrix1 = {{1, 0, 0},
                                    {1, 1, 0},
                                    {0, 1, 0}};
    int result1 = Count(matrix1);
    cout << "Sample input 1 result: " << result1 << endl;  // Expected output: 1

    // Sample input 2
    vector<vector<int>> matrix2 = {{1}};
    int result2 = Count(matrix2);
    cout << "Sample input 2 result: " << result2 << endl;  // Expected output: 0

    return 0;
}
