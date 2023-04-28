#include <bits/stdc++.h>
using namespace std;

// Approach : Straight forward Dynamic Programming approach
// TC : O(N*M) SC : O(N*M)

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
