// Using Breadth First Search (BFS)
// TC : O(N*M)    SC : O(N*M)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    if (A[0][0] == 0) // If starting cell (0,0) contains 0, it's not possible to reach the target.
        return -1;

    vector<vector<int>> vis(N, vector<int>(M, 0)); // To keep track of visited cells
    queue<pair<int, int>> q; // Queue for BFS
    q.push({0, 0});
    vis[0][0] = 1; // Mark the starting cell as visited

    int delrow[] = {-1, 0, 1, 0}; // Array to represent possible changes in rows (up, right, down, left)
    int delcol[] = {0, 1, 0, -1}; // Array to represent possible changes in columns (up, right, down, left)
    int steps = 0; // Initialize the number of steps taken to reach the target cell

    while (!q.empty()) { // Start the BFS traversal
        int size = q.size(); // Get the number of cells at the current level of BFS
        while (size--) { // Process all cells at the current level of BFS
            int row = q.front().first; // Get the row index of the current cell
            int col = q.front().second; // Get the column index of the current cell
            q.pop(); // Remove the current cell from the queue

            if (row == X && col == Y)
                return steps; // If we reach the target cell, return the number of steps taken

            for (int i = 0; i < 4; i++) { // Check all four possible directions (up, right, down, left)
                int nrow = row + delrow[i]; // Calculate the row index of the neighbor cell
                int ncol = col + delcol[i]; // Calculate the column index of the neighbor cell

                // Check if the neighbor cell is within the grid bounds, not visited before, and is reachable (contains 1)
                if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && !vis[nrow][ncol] && A[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1; // Mark the neighbor cell as visited
                    q.push({nrow, ncol}); // Add the neighbor cell to the queue for further exploration
                }
            }
        }
        steps++; // Increment steps for each level of BFS (each iteration represents one level in the graph)
    }

    return -1; // If the target cell is not reachable, return -1
}


int main() {
    // Sample input 1
    int N = 5;
    int M = 5;
    vector<vector<int>> grid1 = {
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
    int targetX1 = 4;
    int targetY1 = 3;

    int steps1 = shortestDistance(N, M, grid1, targetX1, targetY1);
    if (steps1 != -1) {
        cout << "Sample Input 1: Steps to reach target cell: " << steps1 << endl;
    } else {
        cout << "Sample Input 1: Target cell is not reachable." << endl;
    }

    // Sample input 2
    int targetX2 = 2;
    int targetY2 = 4;
    int steps2 = shortestDistance(N, M, grid1, targetX2, targetY2);
    if (steps2 != -1) {
        cout << "Sample Input 2: Steps to reach target cell: " << steps2 << endl;
    } else {
        cout << "Sample Input 2: Target cell is not reachable." << endl;
    }

    return 0;
}
