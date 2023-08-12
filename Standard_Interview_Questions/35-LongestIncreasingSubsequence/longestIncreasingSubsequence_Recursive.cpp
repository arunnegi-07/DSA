// Approach 1 : Recursive Method 
// TC : O(2^N)  SC : O(N) --> Stack Space

#include <iostream>
using namespace std;

// Recursive function to find the length of the longest increasing subsequence
int f(int a[], int index, int prev, int n) {
    // Base case: If we've processed all elements in the array, return 0.
    if (index == n) return 0;
    
    // Recursive case:
    
    // Step 1: Not Take
    // Recursively find the length of the longest increasing subsequence starting from the next index
    int notTake = f(a, index + 1, prev, n);
    
    // Step 2: Take
    int take = 0;
    // Check if it's valid to include the current element in the subsequence.
    // If the previous element (prev) is either not selected (-1) or is smaller than the current element,
    // we can include the current element in the subsequence.
    if (prev == -1 || a[prev] < a[index]) {
        // Include the current element in the subsequence, and recursively find the length of the subsequence
        // starting from the next index.
        take = 1 + f(a, index + 1, index, n);
    }
    
    // Return the maximum of the "take" and "notTake" cases.
    return max(notTake, take);
}

// Function to find the length of the longest increasing subsequence.
int longestSubsequence(int n, int a[]) {  
    // Initialize the starting index as 0 and the previous index as -1 (no previous element initially).
    int index = 0, prev = -1;
    
    // Call the recursive function to calculate the length of the longest increasing subsequence.
    return f(a, index, prev, n);
}


int main() {
    int n1 = 6;
    int a1[] = {5, 8, 3, 7, 9, 1};
    cout << "Longest Increasing Subsequence Length: " << longestSubsequence(n1, a1) << endl;

    int n2 = 8;
    int a2[] = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Longest Increasing Subsequence Length: " << longestSubsequence(n2, a2) << endl;

    return 0;
}
