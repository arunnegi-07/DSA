// Approach 1 : BruteForce Method
// TC : O(nlogn + k)  SC : O(k)

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int>& arr, int n, int k) {
    // Sort the array in descending order
    sort(arr.begin(), arr.end(), greater<int>());

    // Create a result vector and copy the first K elements
    vector<int> result(arr.begin(), arr.begin() + k);

    return result;
}

int main() {
    int N, K;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    cout << "Enter the value of K: ";
    cin >> K;

    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> largestElements = kLargest(arr, N, K);

    cout << "K largest elements in decreasing order: ";
    for (int i = 0; i < largestElements.size(); i++) {
        cout << largestElements[i] << " ";
    }

    return 0;
}
