// Approach 2 : Using Set DataStructure 
// TC : O(N²)  SC : O(N)

// Note : Refer to "Intuition1" file to better understand this approach.

#include <bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        unordered_set<int> hashSet;  // HashSet to store the remaining elements

        // Iterate through the remaining elements as the second element
        for (int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);  // Calculate the required third element

            // Check if the third element exists in the HashSet
            if (hashSet.find(third) != hashSet.end()) {
                return true;  // Triplet found
            }
            hashSet.insert(arr[j]);  // Insert the current element into the HashSet
        }
    }

    return false;  // No triplet found
}

int main() {
    // Example inputs
    int arr1[] = {0, -1, 2, -3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Check for triplets in the first array
    if (findTriplets(arr1, n1))
        cout << "Triplet exists in arr1" << endl;
    else
        cout << "No triplet exists in arr1" << endl;

    // Check for triplets in the second array
    if (findTriplets(arr2, n2))
        cout << "Triplet exists in arr2" << endl;
    else
        cout << "No triplet exists in arr2" << endl;

    return 0;
}