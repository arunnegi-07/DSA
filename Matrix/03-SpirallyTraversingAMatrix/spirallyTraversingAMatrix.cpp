// TC : O(M*N)  SC : O(M*N)

#include <iostream>
#include <vector>
using namespace std;

// Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(vector<vector<int>>& matrix, int r, int c) 
{
    int rowStart = 0, rowEnd = r - 1;
    int colStart = 0, colEnd = c - 1;
  
    vector<int> ans;
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traversing the topmost row
        for (int col = colStart; col <= colEnd; ++col) {
            ans.push_back(matrix[rowStart][col]);
        }
        rowStart++;
        
        // Traversing the rightmost column
        for (int row = rowStart; row <= rowEnd; row++) {
            ans.push_back(matrix[row][colEnd]);                
        }
        colEnd--;
        
        // Traversing the bottom row
        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; col--) {
                ans.push_back(matrix[rowEnd][col]);                
            }
            rowEnd--;
        }
        
        // Traversing the leftmost column
        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                ans.push_back(matrix[row][colStart]);                
            }
            colStart++;
        }
    }
    return ans;
}

int main() {
    // Sample Input 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows1 = 3, cols1 = 3;
    
    // Spiral traversal of matrix1
    vector<int> result1 = spirallyTraverse(matrix1, rows1, cols1);
    
    cout << "Spiral Traversal of Matrix 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    // Sample Input 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };
    int rows2 = 5, cols2 = 4;
    
    // Spiral traversal of matrix2
    vector<int> result2 = spirallyTraverse(matrix2, rows2, cols2);
    
    cout << "Spiral Traversal of Matrix 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
