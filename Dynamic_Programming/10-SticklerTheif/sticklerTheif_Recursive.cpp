// Recursive Method
// TC : O(2^N)  SC : O(N)

#include <iostream>
using namespace std;

//Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return arr[0];

    // Case 1: Rob the current house and skip the next one
    int stealCurrent = arr[0] + FindMaxSum(arr + 2, n - 2);

    // Case 2: Skip the current house
    int skipCurrent = FindMaxSum(arr + 1, n - 1);

    // Return the maximum of the two cases
    return max(stealCurrent, skipCurrent);
}
    
int main() {
    // Test case 1
    int arr1[] = {6, 5, 5, 7, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = FindMaxSum(arr1, n1);
    cout << "Test Case 1: " << result1 << endl;

    // Test case 2
    int arr2[] = {1, 5, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = FindMaxSum(arr2, n2);
    cout << "Test Case 2: " << result2 << endl;

    return 0;
}