/* Approach 3 : Using a Array to keep track if a number is present in range 1 to N or not.
    TC : O(N)  SC : O(N)
    
    This Approach is also very simple to understand,
    We are creating an auxiliary array of size 'N+1' initialized with zeros. Iterate through the input array and increment the count at the 
    corresponding 'index' in the auxiliary array if the element is within the range of the array. 
    Finally, iterate through the auxiliary array starting from index 1 and return the index of the first 'zero' element. The time complexity 
    of this approach is O(N), but it requires O(N) auxiliary space for the auxiliary array.
                                                                                                                                                                                                                                                                        */

#include <bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n) { 
    // Create an auxiliary array of size N+1 initialized with zeros
    vector<int> countArr(n + 1, 0);
    
    // Increment the count at the corresponding index in the auxiliary array
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            countArr[arr[i]]++;
        }
   }
    
    // Find the index of the first zero element in the auxiliary array
    for (int i = 1; i <= n; i++) {
        if (countArr[i] == 0) {
            return i;
        }
    }
    // If all numbers are present, return N+1
    return n + 1;
}

int main() {
    // Sample input 1
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr1, n1) << endl;
    
    // Sample input 2
    int arr2[] = {2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr2, n2) << endl;
    
    return 0;
}