// Approach 1 : Recursive Method
// TC : O(2^N)  SC : O(N)

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive function to calculate the Nth Catalan number
long long Catalan(int n) {
    // Base case: Catalans of 0 and 1 are both 1
    if (n <= 1) {
        return 1;
    }
    
    // Initialize the Catalan number for the current 'n'
    long long catalan = 0;
    
    // Loop to consider all possible combinations of parentheses
    for (int i = 0; i < n; i++) {
        // Calculate the product of two subproblems:
        // 1. Number of Catalan numbers for 'i' left parentheses on the left
        // 2. Number of Catalan numbers for 'n - i - 1' right parentheses on the right
        catalan += Catalan(i) * Catalan(n - i - 1);
        
        // Since the answer can be huge, take the modulo to avoid overflow
        catalan %= MOD;
    }
    
    // Return the calculated Catalan number for the current 'n'
    return catalan;
}

int main() {
    // Sample inputs
    int N1 = 5;
    int N2 = 4;
    
    // Calculate and output the Nth Catalan number for each sample input
    cout << "Catalan(" << N1 << ") = " << Catalan(N1) << endl;
    cout << "Catalan(" << N2 << ") = " << Catalan(N2) << endl;
    
    return 0;
}
