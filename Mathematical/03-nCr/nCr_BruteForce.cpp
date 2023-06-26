// Approach : Brute Force Method (Recursive Formula of nCr)
//  TC :  O(2^n)  SC : O(n)
  
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

// Function to calculate nCr using recursion
int nCr(int n, int r) {
    // Base cases: nCr = 1 when r is 0 or n is equal to r
    if (r == 0 || n == r)
        return 1;
    else
        // Recursive formula: nCr = (n-1)C(r-1) + (n-1)Cr
        return (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
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
