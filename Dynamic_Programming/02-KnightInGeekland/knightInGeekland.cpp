/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Problem : Knight In Geekaland ---> TC : O(N*M) SC : O(N*M)

Knight is at (start_x,start_y) in Geekland which is represented by an NxM 2D matrix.
Each cell in the matrix contains some points. In the ith step, the knight can collect all the points from all the cells that can be visited in exactly i steps
without revisiting any cell.
Also, the knight has some magical powers that enable him to fetch coins from the future i.e. If the knight can collect y coins in the xth step he can fetch all 
the coins that he will collect in the (x + y)th step and if the knight can collect z coins in the yth step he can fetch all the coins that he will collect in
the (y + z)th step and so on without increasing the step count i.e. knight will stay on xth step and will get all the coins of the future steps mentioned 
above((x + y)th step coins + (y+z)th steps + ...).

Find the minimum number of steps required to collect the maximum points.
Note: The knight moves exactly the same as the knight on a chess board. Please follow 0 indexing.

Example 1:

Input:
n = 9
m = 10
start_x = 4, start_y = 5
arr =
0 0 0 2 0 2 0 2 0 0
0 0 2 0 2 0 2 0 2 0
0 2 0 0 1 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 2 0 0 0 2 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 0 0 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 0 0 2 0 2 0 2 0 0
Output: 1
Explanation: minimum knight have to take 1 steps to gain maximum points.
Initially, the knight has 0 coins, he will take 1 step to collect 1 point (sum of cells denoted in red color).
Now in the second step, he can collect points from all the cells colored green i.e. 64 points.
But with his magical power, at the 1st step, he can fetch points from the (1 + 1)th step. Therefore he can collect 1 + 64 coins at step 1 only. Hence answer is 1.

Example 2:

Input:
n = 3 
m = 3
start_x = 2, start_y = 1
arr =
7 6 8
9 1 4
6 2 8
Output:0
Explanation:
Initially, the knight has 2 points, or more formally we can say that at the 0th step knight has 2 points.
In the first step, he can collect points from cells (0, 0) and (0, 2) i.e. 15 points.
In the second step, he can collect points from cells (1, 0) and (1, 2) i.e. 13 coins.
In the third step, he can collect points from cells (2, 0) and (2, 2) i.e. 14 points.
In the fourth step, he can collect points from the cell (0, 1) i.e. 6 points.
So in each step, he can collect coins like -You can see in the below image  Knight can collect 15 coins in the 0th step only

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                                                      */
#include <bits/stdc++.h>
using namespace std;


// Function to check if the given cell (x, y) is inside the grid or not.
bool isSafe(int x, int  y, int rows, int columns){
    if(x < 0 || x >= rows || y < 0 || y >= columns)
        return false;
    return true;
}
    
int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Number of rows and columns in the grid.
        int rows = arr.size(), columns = arr[0].size();
        
        // Possible moves for a knight.
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        // 2D array to keep track of visited cells.
        bool visited[rows][columns] = {};
        
        // Array to store the sum of points earned in each step.
        vector<int> points = {};
        
        // Queue of cells to be visited.
        queue<pair<int,int>> q;
        q.push({start_x,start_y});
        visited[start_x][start_y] = true;
        
        while(!q.empty()){
            int size = q.size();
            int curr_step_points = 0;
            
            // Process all cells in the current step.
            for(int i=0;i<size;i++){
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                curr_step_points += arr[x][y];
                
                // Visit all possible moves from the current cell.
                for(int j=0;j<8;j++){
                    int _x = x + dx[j];
                    int _y = y + dy[j];
                    
                    if(isSafe(_x, _y, rows, columns) && !visited[_x][_y]){
                        visited[_x][_y] = true;
                        q.push({_x,_y});
                    }
                }
            }
            points.push_back(curr_step_points);
        }
        
        // Calculate the total points earned by taking more than one step.
        for(int i=points.size()-1;i>=0;i--){
            if(points[i]+i < points.size()){
                points[i] += points[points[i]+i];
            }
        }
        
        // Find the step that gives the maximum points.
        int max_points = points[0];
        int min_steps = 0;
        for(int i=1;i<points.size();i++){
            if(points[i] > max_points){
                min_steps = i;
                max_points = points[i];
            }
        }
        
    // Return the minimum steps required to earn the maximum points.
    return min_steps;
}


int main(){
    // Sample inputs 1:
    int start_x1 = 0, start_y1 = 0;
    vector<vector<int>> arr1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    
    // Sample inputs 2:
    int start_x2 = 0, start_y2 = 0;
    vector<vector<int>> arr2 = {{5, 7, 8, 6, 6},{7, 7, 8, 6, 6},{5, 7, 7, 7, 6},{5, 5, 7, 7, 6},{5, 5, 7, 7, 7}};
    
    // Sample inputs 3:
    int start_x3 = 2, start_y3 = 2;
    vector<vector<int>> arr3 = {{2, 2, 2},{2, 1, 2},{2, 2, 2}};

    // Call the knightInGeekland function to get the answer.
    int ans1 = knightInGeekland(start_x1, start_y1, arr1);
    int ans2 = knightInGeekland(start_x2, start_y2, arr2);
    int ans3 = knightInGeekland(start_x3, start_y3, arr3);
    
    // Print the result.
    cout << "Minimum steps required to earn the maximum points for 1st Input :" << ans1 << endl;
    cout << "Minimum steps required to earn the maximum points for 2nd Input :" << ans2 << endl;
    cout << "Minimum steps required to earn the maximum points for 3rd Input :" << ans3 << endl;
    
    return 0;
}
