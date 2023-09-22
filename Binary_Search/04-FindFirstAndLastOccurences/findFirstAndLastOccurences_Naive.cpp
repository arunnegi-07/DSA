// Used Standard Binary Search Algorithm
// TC : O(logN)  SC : O(1)

#include <iostream>
#include <vector> 
using namespace std;

vector<int> findOccurrences(int arr[], int n, int x) {
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    // Find the first occurrence
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            firstOccurrence = i;
            break;
        }
    }

    // Find the last occurrence
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == x) {
            lastOccurrence = i;
            break;
        }
    }

    return {firstOccurrence, lastOccurrence};
}

int main() {
    int n = 9;
    int x = 5;
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    vector<int> result = findOccurrences(arr, n, x);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
