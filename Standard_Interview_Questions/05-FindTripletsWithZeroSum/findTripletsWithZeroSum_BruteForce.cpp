// Appraoch 1 : BruteForce --> Checking all the Possibilities
// TC : O(N³)  SC : O(1)

#include <iostream>
using namespace std;

bool findTriplets(int arr[], int n) {
    // Loop through each element as the potential first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Fix the first element and find the remaining two elements
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // Check if the sum of the triplet is zero
                if (arr[i] + arr[j] + arr[k] == 0)
                    return true;  // Triplet found
            }
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
