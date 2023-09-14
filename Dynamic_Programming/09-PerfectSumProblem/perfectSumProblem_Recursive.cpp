// BruteForce --> Recursive Approach
// TC : O(2^N)  SC : O(N) 

#include <iostream>
using namespace std;

int MOD = 1000000007;  // Define a constant for modulo operation.

// Recursive function to count subsets with a given sum.
int perfectSum(int arr[], int N, int sum) {
    // Base case: If there are no elements left in the array,
    // check if the sum is also zero (empty subset).
    if (N == 0) {
        return (sum == 0) ? 1 : 0;
    }

    // Recursive step:
    // 1. Exclude the last element and count subsets without it.
    int excludeLast = perfectSum(arr, N - 1, sum);

    // 2. Include the last element if it doesn't exceed the desired sum
    // and count subsets with the last element.
    int includeLast = 0;
    if (arr[N - 1] <= sum) {
        includeLast = perfectSum(arr, N - 1, sum - arr[N - 1]);
    }

    // Combine the results of the two recursive calls and take modulo.
    int totalSubsets = (excludeLast + includeLast) % MOD;

    return totalSubsets;
}

int main() {
    int arr1[] = {2, 3, 5, 6, 8, 10};
    int N1 = 6;
    int sum1 = 10;

    int result1 = perfectSum(arr1, N1, sum1);
    cout << "Result 1: " << result1 << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int N2 = 5;
    int sum2 = 10;

    int result2 = perfectSum(arr2, N2, sum2);
    cout << "Result 2: " << result2 << endl;

    return 0;
}
