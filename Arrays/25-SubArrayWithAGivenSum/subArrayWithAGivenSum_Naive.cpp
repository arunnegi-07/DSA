/* Approach 1 : Naive Approach  --> Checking all the SubArrays and returning the 'start' and 'end'
                                                            position of first such subarray encountered going from left to right.

    TC : O(N*N)   SC : O(1)                                                                                                                                                                                                                             */

#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> arr, int N, int S) {
    vector<int> result;

    // Iterate through each possible starting index.
    for (int start = 0; start < N; start++) {
        int currentSum = 0;

        // Try all possible subarrays starting from 'start'.
        for (int end = start; end < N; end++) {
            currentSum += arr[end];

            // If the current subarray sum equals S, return the left and right indices.
            if (currentSum == S) {
                result.push_back(start + 1); // Convert to 1-based indexing
                result.push_back(end + 1);   // Convert to 1-based indexing
                return result;
            }
        }
    }

    // If no subarray is found with sum equal to S, return -1.
    result.push_back(-1);
    return result;
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
