/* Approach 1 : BruteForce --> Using Extra Space
   
    TC : O(N)  SC : O(N)

    The solution that immediately comes to mind, involving an additional temporary array, is simpler to 
    implement but requires extra space. However, the mapping approach utilizing the existing array allows
    us to rearrange the elements in-place, satisfying the requirement of O(1) space complexity and that we will
    do in Approach 2 of this problem.
                                                                                                                                */

#include <iostream>
using namespace std;

// Function which will rearrange given array
void arrange(long long arr[], int n) {
    long long ans[n];
    
    // Transform the array elements
    for(int i=0; i<n; i++){
        ans[i] = arr[arr[i]];
    }
    
    // Copy the transformed values back to the original array
    for(int i=0; i<n; i++){
        arr[i] = ans[i];
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
