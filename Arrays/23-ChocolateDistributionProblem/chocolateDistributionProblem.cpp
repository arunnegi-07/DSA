// Using Sorting 
// TC : O(NlogN)  SC : O(1)
 
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference between maximum and minimum chocolates
long long findMinDiff(vector<long long> a, long long n, long long m) {
    // Step 1: Sort the given array in ascending order
    sort(a.begin(), a.end());
    
    // Step 2: Initialize pointers to keep track of the subarray of size 'm'
    int ptr1 = 0;
    int ptr2 = ptr1 + (m - 1);

    // Step 3: Initialize the variable to store the minimum difference
    long long ans = INT_MAX;

    // Step 4: Find the minimum difference between max and min chocolates in subarrays of size 'm'
    while (ptr2 < n) {
        // Calculate the difference between maximum and minimum chocolates in the subarray
        long long diff = a[ptr2] - a[ptr1];

        // Step 5: Update the minimum difference found so far
        ans = min(ans, diff);

        // Step 6: Move the pointers to consider the next subarray of size 'm'
        ptr1++;
        ptr2++;
    }
    
    // Step 7: Return the minimum difference between maximum and minimum chocolates
    return ans;
}

int main() {
    long long N = 8, M = 5;
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    cout << findMinDiff(A, N, M) << endl;

    N = 7, M = 3;
    vector<long long> B = {7, 3, 2, 4, 9, 12, 56};
    cout << findMinDiff(B, N, M) << endl;

    return 0;
}
