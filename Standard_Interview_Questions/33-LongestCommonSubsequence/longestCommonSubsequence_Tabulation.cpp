// Approach 2 :  Dynamic Programming  --> Tabulation Method 
// TC : O(S1*S2)   SC : O(S1*S2) 

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
// between two strings s1 and s2, given their lengths n and m respectively.
int lcs(int n, int m, string s1, string s2) {
    // Create a 2D dp table to store the lengths of LCS for subproblems.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the base cases:
    // - For any prefix of s1 and an empty s2, the LCS length is 0.
    // - For any prefix of s2 and an empty s1, the LCS length is 0.
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Iterate through all possible substrings of s1 and s2.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If the current characters of s1 and s2 match, increment the LCS length.
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // If the characters do not match, take the maximum LCS length from two options:
                // - Excluding the current character of s1 and considering the rest of s2.
                // - Excluding the current character of s2 and considering the rest of s1.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The value at dp[n][m] contains the length of the LCS of the entire strings s1 and s2.
    return dp[n][m];
}

int main() {
    // Sample input 1
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    
    cout << "Sample input 1:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Length of LCS: " << lcs(n, m, s1, s2) << endl;

    // Sample input 2
    string s3 = "ABCBDAB";
    string s4 = "BDCAB";
    int p = s3.length();
    int q = s4.length();
    
    cout << "Sample input 2:" << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "Length of LCS: " << lcs(p, q, s3, s4) << endl;
    
    return 0;
}
