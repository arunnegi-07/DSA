#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Using concept of GCD 
// TC : O(NlogN)  SC : O(1)

// Function to find GCD
int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
    return gcd(b, a % b);
    }

// Function to calculate minimum number
int minimumNumber(int n,vector<int> &arr){
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {
    // sample input 1
    vector<int> arr1 = {2, 4, 6, 8, 10};
    int n1 = arr1.size();
    cout << "Sample Input 1: " << endl;
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Minimum value of Array After performing the operation: " << minimumNumber(n1, arr1) << endl;

    // sample input 2
    vector<int> arr2 = {1, 3, 5, 7, 9};
    int n2 = arr2.size();
    cout << "Sample Input 2: " << endl;
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Minimum value of Array After performing the operation: " << minimumNumber(n2, arr2) << endl;

    return 0;
}
