/* Approach 2 : Without taking Extra Space

    TC : O(N)  SC : O(1)

    Note : Here we will generate Mathematical formula by analyzing the problem and to understand the Intuition
           behind this Approach refer to "Intuition" file attached.
                                                                                                                                */

#include <iostream>
using namespace std;

// Function which will rearrange given array
void arrange(long long arr[], int n) {
    // Step 1: Perform the transformation
    for (int i = 0; i < n; i++) {
        arr[i] += (arr[arr[i]] % n) * n;
    }
    
    // Step 2: Restore the transformed values
    for (int i = 0; i < n; i++) {
        arr[i] /= n;
    }
}

int main() {
    // Sample Input 1
    int n1 = 2;
    long long arr1[] = {1, 0};
    
    cout << "Original Array: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    arrange(arr1, n1);
    
    cout << "Rearranged Array: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // Sample Input 2
    int n2 = 5;
    long long arr2[] = {4, 0, 2, 1, 3};
    
    cout << "Original Array: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    arrange(arr2, n2);
    
    cout << "Rearranged Array: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    return 0;
}