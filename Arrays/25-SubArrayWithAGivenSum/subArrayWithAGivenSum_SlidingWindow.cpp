/* Approach 3 : Using Sliding Window Method 
    TC : O(N)  SC : O(1) 
   
    Note : Refer to 'Intuition_SlidingWindow' file to see the brief explaination about this approach, this approach is simple and very 
                straight forward.
                                                                                                                                                                                                                                                           */
#include <bits/stdc++.h>
using namespace std;

    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int N, long long S)
    {
        int left = 0, right = 0;
        int currentSum = 0;
    
        while (right <= N) {
            if (currentSum == S && left < right) {
                return {left + 1, right}; // Adding 1 for 1-based indexing
            }
    
            if (currentSum <= S) {
                // If current sum is less than or equal to S, extend the window to the right.
                if (right < N) {
                    currentSum += arr[right];
                }
                right++;
            } else {
                // If current sum is greater than S, remove elements from the left.
                currentSum -= arr[left];
                left++;
            }
        }
        // If no subarray is found, return {-1}.
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

