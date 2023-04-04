/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Problem : Shortest XY distance in Grid

Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan distance between a X and a Y.

Manhattan Distance :
| row_index_x - row_index_y | + | column_index_x - column_index_y |

Example 1:                                                                   Example 2:
 
Input:                                                                       Input:
N = 4, M = 4                                                                 N = 3, M = 3
grid  = {{X, O, O, O}                                                        grid = {{X, X, O}
         {O, Y, O, Y}                                                                {O, O, Y}
         {X, X, O, O}                                                                {Y, O, O}}
         {O, Y, O, O}} 
Output:                                                                      Output :
1                                                                            2
Explanation:                                                                 Explanation:
{{X, O, O, O}                                                                {{X, X, O}
{O, Y, O, Y}                                                                  {O, O, Y}
{X, X, O, O}                                                                  {Y, O, O}}
{O, Y, O, O}}                                                                The shortest X-Y distance in the grid is 2.
The shortest X-Y distance in the grid is 1.                                  One possible such X and Y are marked in bold 
One possible such X and Y are marked in bold                                 in the above grid.
in the above grid.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                                                      */
#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force 

int shortest_distance(vector<vector<char>>& grid, int n, int m) {
    // Find the positions of X and Y in the grid
    vector<pair<int, int>> x_positions, y_positions;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                x_positions.push_back({i, j});
            } else if (grid[i][j] == 'Y') {
                y_positions.push_back({i, j});
            }
        }
    }

    // Calculate the minimum Manhattan distance between X and Y
    int min_distance = INT_MAX;
    for (auto x_pos : x_positions) {
        for (auto y_pos : y_positions) {
            int distance = abs(x_pos.first - y_pos.first) + abs(x_pos.second - y_pos.second);
            min_distance = min(min_distance, distance);
        }
    }
    return min_distance;
}

// Approach 2: Using Dynamic Programming

int shortest_distance(vector<vector<char>>& grid,int N,int M) {
    
    vector<vector<int>> distance(N,vector<int>(M,INT_MAX-1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(grid[i][j] == 'X')
                distance[i][j] = 0;
            else{
                if(i-1>=0) // top
                  distance[i][j] = min(distance[i][j],distance[i-1][j] + 1);
                if(j+1<M) // right  --> this step can be eliminated
                  distance[i][j] = min(distance[i][j],distance[i][j+1] + 1);
                if(i+1<N)  // bottom --> this step can be eliminated
                  distance[i][j] = min(distance[i][j],distance[i+1][j] + 1);
                if(j-1>=0)  // left
                  distance[i][j] = min(distance[i][j],distance[i][j-1] + 1);
            }
        }
    }
    
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if(grid[i][j] == 'X')
                distance[i][j] = 0;
            else{
                if(i-1>=0) // top --> this step can be eliminated
                  distance[i][j] = min(distance[i][j],distance[i-1][j] + 1);
                if(j+1<M) // right 
                  distance[i][j] = min(distance[i][j],distance[i][j+1] + 1);
                if(i+1<N)  // bottom 
                  distance[i][j] = min(distance[i][j],distance[i+1][j] + 1);
                if(j-1>=0)  // left --> this step can be eliminated
                  distance[i][j] = min(distance[i][j],distance[i][j-1] + 1);
            }
        }
    }
    
    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(grid[i][j] == 'Y')
                ans = min(ans,distance[i][j]);
        }
    }

    return ans;
}

int main() {
    
    // Example 1
    vector<vector<char>> grid1 = {{'Y', 'O', 'O', 'O', 'O'},
                                  {'O', 'O', 'O', 'O', 'O'},
                                  {'O', 'O', 'O', 'X', 'O'}};

    int n1 = grid1.size();
    int m1 = grid1[0].size();
    int ans1 = shortest_distance(grid1, n1, m1);
    cout << "Example 1: " << ans1 << endl;

    // Example 2
    vector<vector<char>> grid2 = {{'X', 'X', 'O'},
                                  {'O', 'O', 'Y'},
                                  {'Y', 'O', 'O'}};
    int n2 = grid2.size();
    int m2 = grid2[0].size();
    int ans2 = shortest_distance(grid2, n2, m2);
    cout << "Example 2: " << ans2 << endl;

    return 0;
}




        
        








