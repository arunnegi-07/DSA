// Approach 1 :  Recursive Method  --> Checking every Possibilities
// TC : Exponential Time Complexity  SC : O(N)  --> Stack Space

#include <bits/stdc++.h>
using namespace std;

// Recursive function to count the number of ways to make a sum 'sum' using coins from the given array.
// The function considers the coins up to the 'index' position in the array.
long long int f(int coins[], int index, int sum) {
    // Base case 1: If the required sum becomes 0, a valid combination is found.
    if (sum == 0) {
        return 1;
    }
    
    // Base case 2: If we have considered all available coins and the sum is still non-zero,
    // no valid combination can be formed.
    if (index == 0) {
        return (sum % coins[0] == 0); // Check if sum is divisible by the smallest coin.
    }
    
    // Recursively consider two possibilities: taking the coin at 'index' or not taking it.
    
    // Option 1: Take the current coin if its value is less than or equal to the remaining sum.
    long long int take = 0;
    if (coins[index] <= sum) {
        take = f(coins, index, sum - coins[index]);
    }
    
    // Option 2: Do not take the current coin and move to the previous coin.
    long long int notTake = f(coins, index - 1, sum);
    
    // Return the total number of ways by summing up the two possibilities.
    return take + notTake;
}

// Function to count the number of ways to make a sum 'sum' using the given coins.
long long int count(int coins[], int N, int sum) {
    // Call the recursive function 'f' with the given coins and the last index in the array.
    return f(coins, N - 1, sum);
}

int main() {
    // Sample input
    int coins[] = {1, 2, 3};
    int N = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;

    cout << "Number of ways to make sum " << sum << " using given coins: "
         << count(coins, N, sum) << endl;
    
    return 0;
}
