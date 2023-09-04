// TC : O(N*M)  SC : O(N*M)
// Note : Refer to 'Intuition' file attached to get brief intuition behind this problem.

#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int n, int m, int row, int col, vector<vector<char>> &mat, vector<vector<bool>> &vis) {
    // Mark the current cell as visited and change 'O' to '$'
    vis[row][col] = true;
    mat[row][col] = '$';
    
    // Define the four possible directions to move (up, right, down, left)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    // Iterate through all four directions
    for(int i = 0; i < 4; i++) {
        int drow = row + dx[i];
        int dcol = col + dy[i];
        
        // Check if the adjacent cell is within bounds, unvisited, and contains 'O'
        if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && !vis[drow][dcol] && mat[drow][dcol] == 'O') {
            // Recursively explore the adjacent cell
            dfsTraversal(n, m, drow, dcol, mat, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    // Create a boolean matrix to keep track of visited cells
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    // Step 1: Traverse the boundary and mark connected 'O' cells with '$'
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if((row == 0 || row == n - 1 || col == 0 || col == m - 1) && mat[row][col] == 'O') {
                dfsTraversal(n, m, row, col, mat, vis);
            }
        }
    }

    // Step 2: Replace '$' with 'O' and 'O' with 'X' in the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (mat[row][col] == '$') {
                mat[row][col] = 'O';
            } else if (mat[row][col] == 'O') {
                mat[row][col] = 'X';
            }
        }
    }

    // Step 3: Return the modified matrix
    return mat;
}


int main() {
    int n = 5, m = 4;
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    vector<vector<char>> result = fill(n, m, mat);

    // Print the resultant matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
