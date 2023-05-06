// Approach : Recursive Approach
// TC : N^k(Exponential)   SC : O(K) --> At any point of time stack has 'k' entries only.

#include<bits/stdc++.h>
using namespace std;

// A recursive function to find if it's possible to make a change of 'target' cents
// using exactly 'K' coins from 'coins' array.
bool solve(int N, int K, int target, vector<int> &coins) {
        
    // Base case: if k coins used to make target amount, return true
    if (K == 0 and target == 0) return true;
        
    bool ans = false;
        
    // Traverse all coins
    for (int i = 0; i < N; i++) {
            
        // If current coin value is less than or equal to target and we still have more coins to use
        if(target>=coins[i] and K-1>=0)
            // Reduce target amount by current coin value and recurse with k-1 coins
            ans |= solve(N, K - 1, target - coins[i], coins);
    }
    return ans;
}
    
// Wrapper function to call the recursive function
bool makeChanges(int N, int K, int target, vector<int> &coins) {
    return solve(N, K, target, coins);
}

int main() {
    // Sample input 1
    int n = 5, k = 3, target = 11;
    vector<int> coins = {1, 10, 5, 8, 6};
    if (makeChanges(n, k, target, coins)) {
        cout << "Possible to make change of " << target << " cents using exactly " << k << " coins." << endl;
    } else {
        cout << "Not possible to make change of " << target << " cents using exactly " << k << " coins." << endl;
    }

    // Sample input 2
    int m = 3, p = 5, q = 25;
    vector<int> c = {7, 2, 4};
    if (makeChanges(m, p, q, c)) {
        cout << "Possible to make change of " << q << " cents using exactly " << p << " coins." << endl;
    } else {
        cout << "Not possible to make change of " << q << " cents using exactly " << p << " coins." << endl;
    }
    return 0;
}