// Approach 1 : Naive Approach
// TC : O(N*N)  SC : O(N)  --> for returning answer

// So, Naive Approach is simple just checking each number separately if it is a leader or not.

#include <bits/stdc++.h>
using namespace std;

// Function to find leaders in an array.
vector<int> findLeaders(int arr[], int n) {
    // Initialize a vector to store the leaders.
    vector<int> leaders;

    // Iterate through the array elements.
    for (int i = 0; i < n; i++) {
        // Assume the current element is a leader until proven otherwise.
        bool isLeader = true;

        // Compare the current element with all elements to its right.
        for (int j = i + 1; j < n; j++) {
            // If we find an element to the right that is greater than the current element,
            // it means the current element is not a leader.
            if (arr[i] < arr[j]) {
                isLeader = false;
                break; // No need to check further for this element.
            }
        }

        // If after checking all elements to the right, the current element is still considered a leader,
        // add it to the leaders vector.
        if (isLeader) {
            leaders.push_back(arr[i]);
        }
    }
    // Return the vector containing the leaders.
    return leaders;
}

int main() {
    int arr1[] = {16, 17, 4, 3, 5, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    vector<int> leaders1 = findLeaders(arr1, n1);
    
    cout << "Leaders in the first array: ";
    for (int leader : leaders1) {
        cout << leader << " ";
    }
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    vector<int> leaders2 = findLeaders(arr2, n2);
    
    cout << "Leaders in the second array: ";
    for (int leader : leaders2) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
