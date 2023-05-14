// TC : O(2^N)  SC : O(1)
// This Problem is just the variation of 0/1 Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

/*
This function recursively finds the maximum subset sum that can be obtained by choosing or not choosing each element in the vector A.
notTaken: a flag indicating whether the previous element was not taken in the subset sum.
i: the current index of the element being considered in A.
*/
long long helper(vector<int> A, int notTaken, int i) {
    if(i == A.size()) return 0;
    if(notTaken == 1)
        return helper(A, 0, i+1) + A[i];

    return max(helper(A, 1, i+1), helper(A, 0, i+1) + A[i]);
}

/*
This function returns the maximum subset sum that can be obtained from the vector A.
N: the size of vector A.
A: the input vector.
*/
long long findMaxSubsetSum(int N, vector<int> &A) {
    return helper(A, 0, 0);
}

int main() {
    // Example input 1
    int N1 = 5;
    vector<int> A1 = {1, 2, 3, -2, 5};
    cout << "Example input 1: " << findMaxSubsetSum(N1, A1) << endl;

    // Example input 2
    int N2 = 4;
    vector<int> A2 = {1, 2, -5, 3};
    cout << "Example input 2: " << findMaxSubsetSum(N2, A2) << endl;

    return 0;
}
