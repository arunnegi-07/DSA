// TC : O(n*m)  SC : O(n*m)

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

// Function to find unique rows in a binary matrix
vector<vector<int>> uniqueRow(int arr[MAX][MAX], int n, int m)
{
    vector<vector<int>> ans; // Vector to store the unique rows
    
    set<vector<int>> st; // Set to track unique rows encountered so far

    // Iterate over each row of the matrix
    for (int i = 0; i < n; i++) {
        vector<int> curr; // Vector to store the elements of the current row
        
        // Iterate over each column of the current row
        for (int j = 0; j < m; j++) {
            curr.push_back(arr[i][j]); // Push the element into the current row vector
        }
        
        // Check if the current row vector is already in the set of unique rows
        if (st.find(curr) == st.end()) {
            st.insert(curr); // Insert the current row vector into the set
            ans.push_back(curr); // Push the current row vector into the vector of unique rows
        }
    }
    
    return ans; // Return the vector of unique rows
}

int main() {
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    
    int matrix[MAX][MAX];
    cout << "Enter the matrix elements row-wise (0 or 1):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> uniqueRows = uniqueRow(matrix, row, col);
    
    cout << "Unique rows in the matrix:" << endl;
    for (const auto& row : uniqueRows) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    return 0;
}
