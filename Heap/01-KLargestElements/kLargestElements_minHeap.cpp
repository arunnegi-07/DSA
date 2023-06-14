// Approach 3 : Using minHeap
// TC : O(k*logk + (n-k)*logk)   SC : O(k) (for minHeap)

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int>& arr, int n, int k) {
    // Create a min-heap to store the K largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert the first K elements into the min-heap
    // It will take O(k*logk)
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }

    // For the remaining elements, if any element is larger than the minimum element in the min-heap,
    // remove the minimum element and insert the larger element into the min-heap
    // It will take O((n-k)*logk)
    for (int i = k; i < n; i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    // Create a result vector and fill it with the K largest elements in decreasing order
    vector<int> result;

    // It wiil take O(k*logk)
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse the result vector to get the elements in decreasing order
    // It will take O(k*logk)
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    // Example 1
    int arr1[] = {12, 5, 787, 1, 23};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    vector<int> input1(arr1, arr1 + n1);
    vector<int> result1 = kLargest(input1, n1, k1);
    cout << "Example 1 Output: ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // Example 2
    int arr2[] = {1, 23, 12, 9, 30, 2, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    vector<int> input2(arr2, arr2 + n2);
    vector<int> result2 = kLargest(input2, n2, k2);
    cout << "Example 2 Output: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}