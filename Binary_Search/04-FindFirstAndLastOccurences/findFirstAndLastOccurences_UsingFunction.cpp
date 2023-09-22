// Used lower_bound and upper_bound functions in C++
// TC : O(logN)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x ){
    // Use std::lower_bound to find the first occurrence of x
    int* firstIt = lower_bound(arr, arr + n, x);

    // Use std::upper_bound to find the position just after the last occurrence of x
    int* lastIt = upper_bound(arr, arr + n, x);
    
    if (firstIt != arr + n && *firstIt == x) {
        // Calculate the index of the first occurrence
        int firstOccurrence = firstIt - arr;
        
        // Calculate the index of the last occurrence (subtract 1 from the upper_bound result)
        int lastOccurrence = (lastIt - 1) - arr;
        
        return {firstOccurrence,lastOccurrence};
    } else {
        // If x is not found in the array, both indices are set to -1
        return {-1,-1};
    }
}

int main() {
    int n = 9;
    int x = 5;
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    vector<int> result = findOccurrences(arr, n, x);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
