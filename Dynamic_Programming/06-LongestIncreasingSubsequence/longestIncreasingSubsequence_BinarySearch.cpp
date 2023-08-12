// Approach 4 : Using Binary Search --> Time as well as Space Optimized Solution
// TC : O(N*logN)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence.
int longestSubsequence(int N, int a[]) {  
    // Create a temporary vector to store the current increasing subsequence.
    vector<int> temp;
    
    // Initialize the temporary vector with the first element of the given array.
    temp.push_back(a[0]);
    
    // Traverse through the remaining elements of the array.
    for (int i = 1; i < N; i++) {
        // If the current element is greater than the last element of the subsequence,
        // extend the subsequence by appending the current element.
        if (a[i] > temp.back()) {
            temp.push_back(a[i]);
        }
        // If the current element is not greater than the last element of the subsequence,
        // find the position where the current element can replace an existing element
        // while maintaining the increasing order.
        else {
            // Find the index of the smallest element in the subsequence that is greater than or equal to the current element.
            int index = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            
            // Replace the element at the found index with the current element.
            temp[index] = a[i];
        }
    }
    
    // The size of the temporary vector represents the length of the longest increasing subsequence.
    return temp.size();
}

int main() {
    int N = 6;
    int a[] = {5, 8, 3, 7, 9, 1};
    
    cout << "Longest Increasing Subsequence Length: " << longestSubsequence(N, a) << endl;

    return 0;
}
