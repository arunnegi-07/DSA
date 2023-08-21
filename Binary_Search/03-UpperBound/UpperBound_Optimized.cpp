// Approach 2 : Used concept of Binary Search to tream down search space every time to half.
// TC : O(logN)  SC : O(1)
   
#include <bits/stdc++.h>
using namespace std;

// Function to find the upper bound of 'x' in a sorted vector 'arr' using binary search
int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Initialize ans to n, assuming 'x' is greater than all elements

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] > x) { // If the middle element is greater than  'x'
            ans = mid; // Update ans to the current index
            high = mid - 1; // Move to the left half to search for a smaller index
        } else {
            low = mid + 1; // Move to the right half to search for a greater index
        }
    }
    return ans;
}

int main() {
    // Sample input 1
    vector<int> arr1 = {1, 3, 5, 6, 7, 9};
    int n1 = arr1.size();
    int x1 = 6;

    int result1 = upperBound(arr1, n1, x1);

    if (result1 != n1) {
        cout << "upper bound of " << x1 << " in sample input 1 is at index " << result1 << ". Element: " << arr1[result1] << endl;
    } else {
        cout << x1 << " is greater than all elements in sample input 1." << endl;
    }

    // Sample input 2
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int n2 = arr2.size();
    int x2 = 5;

    int result2 = upperBound(arr2, n2, x2);

    if (result2 != n2) {
        cout << "upper bound of " << x2 << " in sample input 2 is at index " << result2 << ". Element: " << arr2[result2] << endl;
    } else {
        cout << x2 << " is greater than all elements in sample input 2." << endl;
    }

    return 0;
}
