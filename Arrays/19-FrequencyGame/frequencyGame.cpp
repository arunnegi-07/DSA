// TC : O(N)  SC : O(N)

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// Function to find the largest element with the minimum frequency
int LargButMinFreq(int arr[], int n) {
    unordered_map<int, int> freq; // Map to store the frequency of each value

    // Storing the frequency of each value inside the map
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int mini = INT_MAX; // Variable to store the minimum frequency
    int ans = -1; // Variable to store the answer

    // Iterating over the map entries
    for (auto entry : freq) {
        // If the frequency of the current value is less than the minimum
        if (entry.second < mini) {
            ans = entry.first; // Update the answer to the current value
            mini = entry.second; // Update the minimum frequency
        }
        // If the frequency of the current value is equal to the minimum
        // and the current value is larger than the current answer
        else if (entry.second == mini && entry.first > ans) {
            ans = entry.first; // Update the answer to the current value
        }
    }

    return ans; // Return the answer
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 6, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // Expected output: 4
    cout << "Largest element with minimum frequency in arr1: " << LargButMinFreq(arr1, n1) << endl;

    int arr2[] = {10, 20, 30, 30, 30, 40, 40, 50, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // Expected output: 10
    cout << "Largest element with minimum frequency in arr2: " << LargButMinFreq(arr2, n2) << endl;

    return 0;
}
