// Approach 2 : Dynamic Programming --> Memoization 
// TC : O(N^2)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive function with memoization to calculate the Nth Catalan number
long long Catalan(int n, vector<long long> &dp) {
    // Base case: Catalans of 0 and 1 are both 1
    if (n <= 1) {
        return 1;
    }
    
    // If the value is already computed, return it
    if (dp[n] != -1) {
        return dp[n];
    }
    
    // Initialize the Catalan number for the current 'n'
    long long catalan = 0;
    
    // Loop to consider all possible combinations of parentheses
    for (int i = 0; i < n; i++) {
        // Calculate the product of two subproblems:
        // 1. Number of Catalan numbers for 'i' left parentheses on the left
        // 2. Number of Catalan numbers for 'n - i - 1' right parentheses on the right
        catalan += (Catalan(i, dp) * Catalan(n - i - 1, dp)) % MOD;
        
        // Since the answer can be huge, take the modulo to avoid overflow
        catalan %= MOD;
    }
    
    // Save the calculated Catalan number for the current 'n' in dp table
    return dp[n] = catalan;
}

// Function to find the Nth Catalan number using memoization
int findCatalan(int n) {
    vector<long long> dp(n + 1, -1);
    return static_cast<int>(Catalan(n, dp));
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
