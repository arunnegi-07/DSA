// Dynamic Programming --> Memoization Method

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

// Function to count the number of ways to represent 'n' as the sum of powers of integers
int countWays(int n, int x, int currentNum, std::vector<std::vector<int>>& memo) {
    if (n == 0) {
        return 1;  // Found a valid combination
    }
    if (n < 0 || currentNum <= 0) {
        return 0;  // Invalid combination
    }

    if (memo[n][currentNum] != -1) {
        return memo[n][currentNum];  // Return memoized result
    }

    int includeCurrent = countWays(n - pow(currentNum, x), x, currentNum - 1, memo);
    int excludeCurrent = countWays(n, x, currentNum - 1, memo);

    // Compute the total number of ways modulo MOD and store it in the memoization table
    memo[n][currentNum] = (includeCurrent + excludeCurrent) % MOD;

    return memo[n][currentNum];
}

// Function to calculate the number of ways to represent 'n' as the sum of x-th powers of integers
int numOfWays(int n, int x) {
    vector<vector<int>> memo(n + 1, std::vector<int>(n + 1, -1));
    return countWays(n, x, static_cast<int>(pow(n, 1.0 / x)), memo);
}

int main() {
    // Example 1:
    int n1 = 10;
    int x1 = 2;
    int ways1 = numOfWays(n1, x1);
    std::cout << "Number of ways to represent " << n1 << " as the sum of " << x1 << "-th powers of integers: " << ways1 << std::endl;

    // Example 2:
    int n2 = 15;
    int x2 = 3;
    int ways2 = numOfWays(n2, x2);
    std::cout << "Number of ways to represent " << n2 << " as the sum of " << x2 << "-th powers of integers: " << ways2 << std::endl;

    return 0;
}
