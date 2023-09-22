// Naive Approach
// TC : O(N)  SC : O(1)

#include <iostream>
#include <vector>

using namespace std;

vector<int> findOccurrences(int arr[], int n, int x) {
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    // Binary search for the first occurrence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            firstOccurrence = mid;
            high = mid - 1; // Continue searching on the left side
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Binary search for the last occurrence
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            lastOccurrence = mid;
            low = mid + 1; // Continue searching on the right side
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
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
