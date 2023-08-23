/* TC : O(N*M*k)  SC : O(1)
   where k = size of given word
                                                                                                                                                 
   Note: Solution looks very huge but the actual concept behind is very easy, so to get the Intuition behind the approach to solve this
         problem refer to the file named 'Intuition' attached with the same folder.                                                                                                                                                 
                                                                                                                                                    */

#include<bits/stdc++.h>
using namespace std;

// Function to find word occurrences in the grid
bool helper(int row, int col, int dx, int dy, vector<vector<char>> &grid, string word) {
    int i = grid.size();
    int j = grid[0].size();
    
    for (int x = 2; x < word.size(); x++) {
        row += dx;
        col += dy;
        
        // Check if the new position (row, col) is within the grid bounds
        if (row >= 0 && row < i && col >= 0 && col < j) {
            if (grid[row][col] != word[x]) {
                return false;  // Mismatch in characters
            }
        } else {
            return false;  // Position is out of bounds
        }
    }
    return true;  // All characters in the word match in this direction
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
    int rowCount = grid.size();
    int colCount = grid[0].size();
    
    // Define directions for movement: 8 possible directions
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    vector<vector<int>> ans;
    
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            if (grid[row][col] == word[0]) {  // Found the first character of the word
                // If the word is of length '1', add the position to the result
                if (word.size() == 1) {
                    ans.push_back({row, col});
                    continue;
                } 
                
                // Check all 8 directions for the rest of the word
                for (int i = 0; i < 8; i++) {
                    int drow = row + dx[i];
                    int dcol = col + dy[i];
                    
                    // Check if the new position is within bounds and the next character matches
                    if (drow >= 0 && drow < rowCount && dcol >= 0 && dcol < colCount && grid[drow][dcol] == word[1]) {
                        if (helper(drow, dcol, dx[i], dy[i], grid, word)) {
                            ans.push_back({row, col});  // Found the word in this direction
                            break;
                        }
                    }
                }
            }
        }
    }
    return ans;  // Return the list of positions where the word is found
}


int main() {
    // Sample Input 1
    vector<vector<char>> grid1 = {
        {'a', 'b', 'c'},
        {'d', 'r', 'f'},
        {'g', 'h', 'i'}
    };
    string word1 = "abc";

    vector<vector<int>> result1 = searchWord(grid1, word1);
    cout << "Sample Input 1 Result: " << endl;
    for (const vector<int>& pos : result1) {
        cout << "(" << pos[0] << ", " << pos[1] << ") ";
    }
    cout << endl;

    // Sample Input 2
    vector<vector<char>> grid2 = {
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'e', 'b'},
        {'e', 'b', 'e', 'b'}
    };
    string word2 = "abe";

    vector<vector<int>> result2 = searchWord(grid2, word2);
    cout << "Sample Input 2 Result: " << endl;
    for (const vector<int>& pos : result2) {
        cout << "(" << pos[0] << ", " << pos[1] << ") ";
    }
    cout << endl;

    return 0;
}
