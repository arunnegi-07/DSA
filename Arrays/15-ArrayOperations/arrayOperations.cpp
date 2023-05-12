// TC : O(N)   SC : O(1)
// In this problem we just need to count the Sub-Arrays which doesn't contain any Zero.

#include <bits/stdc++.h>
using namespace std;

int arrayOperations(int n, vector<int> &arr) {
    int ans=0; // initialize the answer variable to 0
    bool flag=false,allNonZero=true; // initialize the flag and allNonZero variables to false

    // iterate over the array
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0) // if the current element is non-zero
        {
            if(flag==false) ans++; // if this is the first non-zero element in a sub-array, increment the answer
            flag=true; // set the flag to true
        }
        else // if the current element is 0
        {
            allNonZero=false; // set allNonZero to false
            flag=false; // set the flag to false
        }
    }

    if(allNonZero) return -1; // if all elements are non-zero, return -1
    
    return ans; // return the answer
}

int main() {
    // Sample input 1
    vector<int> arr1 = {3,0,4,5};
    int n1 = arr1.size();
    int result1 = arrayOperations(n1, arr1);
    cout << "Sample input 1: " << result1 << endl;

    // Sample input 2
    vector<int> arr2 = {10,4,9,6,10,10,4,4};
    int n2 = arr2.size();
    int result2 = arrayOperations(n2, arr2);
    cout << "Sample input 2: " << result2 << endl;

    return 0;
}
