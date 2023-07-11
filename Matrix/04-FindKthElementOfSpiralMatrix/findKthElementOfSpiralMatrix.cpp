/* TC : O(M*N)  SC : O(1)
    Note : This problem is exact similar to previous one, but in that instead of traversing the entire matrix spirally we will just traverse till
    'count' become equal to 'k', and then we will return back that value we are at .
                                                                                                                                                                                                                                                                                    */

#include <iostream>
using namespace std;

const int MAX = 100;

int findK(int matrix[MAX][MAX], int n, int m, int k) {
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = m - 1;
    int count = 0;   

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traversing top row
        for (int col = colStart; col <= colEnd; ++col) {
            count++;
            if (count == k) return matrix[rowStart][col];
        }
        ++rowStart;

        // Traversing the rightmost column
        for (int row = rowStart; row <= rowEnd; ++row) {
            count++;
            if (count == k) return matrix[row][colEnd];
        }
        --colEnd;

        // Traversing the bottom row
        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; --col) {
                count++;
                if (count == k) return matrix[rowEnd][col];
            }
            --rowEnd;
        }

        // Traversing the leftmost column
        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; --row) {
                count++;
                if (count == k) return matrix[row][colStart];
            }
            ++colStart;
        }
    }

    // Kth element not found
    return -1;
}

int main() {
    // sample input 1 
    int matrix1[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n1 = 3; // Number of rows
    int m1 = 3; // Number of columns
    int k1 = 5; // Kth element to find
   
   // sample input 2
    int matrix2[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n2 = 4; // Number of rows
    int m2 = 4; // Number of columns
    int k2 = 10; // Kth element to find

    int kthElement1 = findK(matrix1, n1, m1, k1);
    if (kthElement1 != -1) {
        cout << "The " << k1 << "th element in the matrix is: " << kthElement1 << endl;
    } else {
        cout << "The " << k1 << "th element does not exist in the matrix." << endl;
    }

    int kthElement2 = findK(matrix2, n2, m2, k2);
    if (kthElement2 != -1) {
        cout << "The " << k2 << "th element in the matrix is: " << kthElement2 << endl;
    } else {
        cout << "The " << k2 << "th element does not exist in the matrix." << endl;
    }

    return 0;
}
