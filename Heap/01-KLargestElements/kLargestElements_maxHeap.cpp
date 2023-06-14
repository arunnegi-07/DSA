// Approach 2 : Using maxHeap

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int> maxHeap; // Create a max heap to store elements in descending order

    // Insert all elements from the array into the max heap
    for (int i = 0; i < n; i++) {
        maxHeap.push(arr[i]);
    }

    vector<int> ans; // Create a vector to store the k largest elements
    for (int i = 0; i < k; i++) {
        int val = maxHeap.top(); // Get the current largest element from the max heap
        maxHeap.pop(); // Remove the largest element from the max heap
        ans.push_back(val); // Add the largest element to the result vector
    }

    return ans; // Return the vector containing the k largest elements
}

int main() {
    // Example 1
    int arr1[] = {12, 5, 787, 1, 23};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    vector<int> result1 = kLargest(arr1, n1, k1);
    cout << "Example 1 Output: ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // Example 2
    int arr2[] = {1, 23, 12, 9, 30, 2, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    vector<int> result2 = kLargest(arr2, n2, k2);
    cout << "Example 2 Output: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}

