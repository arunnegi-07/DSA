// Approach 2 : Optimal Solution
// TC  : O(N)  SC : O(N)

// Note : Refer to 'Intuition' file attached to get proper Intuition behind the problem.

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n) {
    // Step 1: Initialize a variable to keep track of the maximum element seen so far.
    int maxi = INT_MIN;

    // Create an array to store the maximum element to the right of each element.
    int maxAtRight[n];

    // Calculate the maximum element to the right at every index.
    for (int i = n - 1; i >= 0; i--) {
        // Update 'maxi' if we encounter a new maximum element.
        maxi = max(maxi, a[i]);
        
        // Store the maximum element seen so far to the right of the current index.
        maxAtRight[i] = maxi;
    }

    // Step 2: Create a vector to store the leaders.
    vector<int> leaders;

    // Check if each element is a leader.
    for (int i = 0; i < n - 1; i++) {
        // If the current element is greater than or equal to the maximum element
        // to the right of it, it is a leader.
        if (a[i] >= maxAtRight[i]) {
            leaders.push_back(a[i]);
        }
    }

    // The rightmost element is always a leader.
    leaders.push_back(a[n - 1]);

    // Return the vector containing the leaders.
    return leaders;
}

int main() {
    int arr1[] = {16, 17, 4, 3, 5, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    vector<int> leaders1 = leaders(arr1, n1);

    cout << "Leaders in the first array: ";
    for (int leader : leaders1) {
        cout << leader << " ";
    }
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> leaders2 = leaders(arr2, n2);

    cout << "Leaders in the second array: ";
    for (int leader : leaders2) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
