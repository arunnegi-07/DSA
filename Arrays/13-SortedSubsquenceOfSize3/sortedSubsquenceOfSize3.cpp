// TC : O(N)  SC : O(N)
// Note : Here we have to return any of the 3 elements which satisfies the given condition.

#include <bits/stdc++.h>
using namespace std;

vector<int> find3Numbers(vector<int> arr, int N){
    vector<int>ans; // vector to store answer
    vector<int>rightmax(N);
    int maxx = INT_MIN;
        
    // Finding the maximum element to the right of each element in the array.
    for(int i=N-1;i>=0;i--){
        if(maxx < arr[i]){
            maxx = arr[i];
        }
        rightmax[i] = maxx;
    }
        
    // This initializes a variable mini to the maximum possible integer value to start the loop.
    int mini=INT_MAX;
        
    for(int i=0;i<N;i++){
        // This checks if the current element 'arr[i]' is less than the minimum value seen so 
        // far 'mini', and updates 'mini' accordingly.
        if(mini>arr[i]){
            mini=arr[i];
        }
        // This checks if the current element 'arr[i]' is greater than the minimum value seen so far 
        // 'mini' and less than the maximum value to its right 'rightmax[i]'.
        else if(mini<arr[i] and arr[i]<rightmax[i]){
            // This adds the three numbers that meet the above conditions to the ans vector and
            // breaks out of the loop.
            ans.push_back(mini);
            ans.push_back(arr[i]);
            ans.push_back(rightmax[i]);
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 0, 4, 3, 5};
    int N1 = 6;
    vector<int> ans1 = find3Numbers(arr1, N1);
    if (ans1.empty()) {
        cout << "No such triplet exists" << endl;
    } else {
        cout << "The triplet is: ";
        for (int x : ans1) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    vector<int> arr2 = {5, 4, 3, 2, 1};
    int N2 = 5;
    vector<int> ans2 = find3Numbers(arr2, N2);
    if (ans2.empty()) {
        cout << "No such triplet exists" << endl;
    } else {
        cout << "The triplet is: ";
        for (int x : ans2) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
