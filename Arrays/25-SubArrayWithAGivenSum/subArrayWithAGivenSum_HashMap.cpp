// Approach 2 : HashMap + PrefixSum 
// TC : O(N)  SC : O(N) 

// Note : Refer to 'Intuition_Map' file to get proper explaination of the Intuition behind this approach.

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long sum) {
    // Create an unordered map to store the prefix sums and their corresponding position.
    unordered_map<long long, int> prefix;

    // Initialize the prefix sum and the map with an initial entry, it is necessary 
    prefix[0] = 0;
    long long preSum = 0;

    // Iterate through the input array.
    for (int i = 0; i < n; i++) {
        // Calculate the prefix sum by adding the current element to the previous prefix sum.
        preSum += arr[i];

        // Check if there exists a prefix sum (preSum - sum) in the map.
        if (prefix.find(preSum - sum) != prefix.end()) {
            // If found, return the indices of the subarray.
            // Note: We add 1 to the indices to convert to 1-based indexing.
            return {prefix[preSum - sum] + 1, i + 1};
        }

        // Store the current prefix sum along with its postition {position is index +1} in the map.
        prefix[preSum] = i + 1;
    }

    // If no subarray with the given sum is found, return {-1}.
    return {-1};
}

int main() {
    int N = 5;
    int S = 12;
    vector<int> A = {1, 2, 3, 7, 5};

    vector<int> indices = subarraySum(A, N, S);

    if (indices[0] == -1) {
        cout << "No subarray found with sum " << S << std::endl;
    } else {
        cout << "Subarray found from index " << indices[0] << " to " << indices[1] << std::endl;
    }

    return 0;
}

