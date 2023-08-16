// Approach 3 : Dynamic Programming --> Tabulation Method 
// TC : O(N^2)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to find the Nth Catalan number using tabulation
int findCatalan(int n) {
    vector<long long> dp(n + 1, 0);
    
    // Base cases: Catalan numbers for 0 and 1
    dp[0] = 1;
    dp[1] = 1;
    
    // Iterate from 2 to n
    for (int i = 2; i <= n; i++) {
        // Initialize the Catalan number for the current 'i'
        for (int j = 0; j < i; j++) {
            // Calculate the product of two subproblems:
            // 1. Number of Catalan numbers for 'j' left parentheses on the left
            // 2. Number of Catalan numbers for 'i - j - 1' right parentheses on the right
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
        }
    }
    
    // Return the calculated Catalan number for 'n'
    return dp[n];
}

int main() {
    // Sample inputs
    int N1 = 5;
    int N2 = 4;
    
    // Calculate and output the Nth Catalan number for each sample input
    cout << "Catalan(" << N1 << ") = " << findCatalan(N1) << endl;
    cout << "Catalan(" << N2 << ") = " << findCatalan(N2) << endl;
    
    return 0;
}
