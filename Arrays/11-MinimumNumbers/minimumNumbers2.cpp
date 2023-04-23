#include<bits/stdc++.h>
using namespace std;

// Approach 2 : Two Pointers Approach
// TC : O(N)  SC : O(1)

// Function to calculate minimum number
int minimumNumber(int n,vector<int> &arr){
    int l = 0, r = arr.size()-1;
    while(l<r)
    {
        if(arr[l]>=arr[r])       
            arr[l] = arr[l]%arr[r];
        else                       
            arr[r] = arr[r]%arr[l];
        if(arr[l]==0)           
            l++;
        else if(arr[r]==0)
            r--;
    }
    return arr[l];
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
