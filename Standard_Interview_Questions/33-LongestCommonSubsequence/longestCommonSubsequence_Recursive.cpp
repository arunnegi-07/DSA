// Approach 1 :  Recursive Method  --> Checking every Subsequence
// TC : Exponential Time Complexity  SC : O(N)  --> Stack Space

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the length of the Longest Common Subsequence (LCS)
// between two strings s1 and s2, given their lengths n and m respectively.
int f(int n, int m, string &s1, string &s2) {
    // Base case: If either of the string lengths becomes negative, return 0.
    if (n < 0 || m < 0) {
        return 0;
    }
    
    // If the characters at positions n and m in the two strings match,
    // increment the LCS length by 1 and recursively move to the previous positions.
    if (s1[n] == s2[m]) {
        return 1 + f(n - 1, m - 1, s1, s2);
    }
    
    // If the characters do not match, calculate the LCS length by considering two cases:
    // 1. Exclude the current character from s1 and move to the previous position in s2 (m-1).
    // 2. Exclude the current character from s2 and move to the previous position in s1 (n-1).
    return max(f(n, m - 1, s1, s2), f(n - 1, m, s1, s2));
}

// Function to find the length of the Longest Common Subsequence (LCS)
// between two strings s1 and s2, given their lengths n and m respectively.
int lcs(int n, int m, string s1, string s2) {
    // Call the recursive function 'f' with adjusted indices (n-1, m-1) to start from the last characters of s1 and s2.
    return f(n - 1, m - 1, s1, s2);
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
    cout << "Length of LCS: " << lcs(n, m, s1, s2) << endl;  // Ex: GTAB

    // Sample input 2
    string s3 = "ABCBDAB";
    string s4 = "BDCAB";
    int p = s3.length();
    int q = s4.length();
    
    cout << "Sample input 2:" << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "Length of LCS: " << lcs(p, q, s3, s4) << endl;  // Ex: BDAB
    
    return 0;
}
