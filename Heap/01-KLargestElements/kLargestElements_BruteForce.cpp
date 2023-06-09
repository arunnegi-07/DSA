// Approach 1 : BruteForce Method
// TC : O(nlogn + k)  SC : O(k)

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    // Sort the array in descending order
    sort(arr, arr + n, greater<int>());

    // Create a result vector and copy the first K elements
    vector<int> result(arr, arr + k);

    return result;
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