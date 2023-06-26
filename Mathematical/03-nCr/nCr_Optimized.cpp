// Approach : Optimized --> Tabulation Method
// TC : O(n*r)  SC : O(r)

// Note : Refer to "Intuition" file attached to got clear idea behind this approach.

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate nCr using dynamic programming
int nCr(int n, int r) {
    // Base case: if n < r, nCr is not possible, return 0
    if (n < r)
        return 0;

    // Adjust r if it is greater than n-r for efficiency
    if (r < n - r)
        r = n - r;

    int dp[r + 1] = {0}; // Initialize the dynamic programming array
    dp[0] = 1; // Base case: nC0 = 1

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
            // Calculate nCr by adding the previous row's value (dp[j])
            // and the value at the previous column (dp[j-1])
            // Take modulo MOD to avoid overflow
        }
    }

    return dp[r]; // Return the value of nCr
}

int main() {
    // Sample input 1
    int n = 3, r = 2;
    int result = nCr(n, r);
    cout << "nCr(" << n << ", " << r << ") = " << result << endl;  // Output: nCr(3, 2) = 3

    // Sample input 2
    n = 2;
    r = 4;
    result = nCr(n, r);
    cout << "nCr(" << n << ", " << r << ") = " << result << endl;  // Output: nCr(2, 4) = 0

    return 0;
}
