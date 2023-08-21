// Approach 1 : Naive Approach  --> Simple straight forward linear search
// TC : O(N)  SC : O(1)

#include <iostream>
#include <vector>
using namepace std;

// Function to find the upper bound of 'x' in a sorted vector 'arr'
int upperBound(vector<int> arr, int n, int x) {
    int upperBoundIndex = -1;  // Initialize with an invalid index

    for (int i = 0; i < n; ++i) {
        if (arr[i] > x) {
            upperBoundIndex = i;
            break;  // Found the upper bound, exit the loop
        }
    }
    return upperBoundIndex;
}

int main() {
    // Sample input 1
    vector<int> arr1 = {1, 3, 5, 6, 7, 9};
    int n1 = arr1.size();
    int x1 = 6;

    int result1 = upperBound(arr1, n1, x1);

    if (result1 != -1) {
        cout << "upper bound of " << x1 << " in sample input 1 is at index " << result1 << ". Element: " << arr1[result1] << endl;
    } else {
        cout << x1 << " is greater than all elements in sample input 1." << endl;
    }

    // Sample input 2
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int n2 = arr2.size();
    int x2 = 5;

    int result2 = upperBound(arr2, n2, x2);

    if (result2 != -1) {
        cout << "upper bound of " << x2 << " in sample input 2 is at index " << result2 << ". Element: " << arr2[result2] << endl;
    } else {
        cout << x2 << " is greater than all elements in sample input 2." << endl;
    }

    return 0;
}
