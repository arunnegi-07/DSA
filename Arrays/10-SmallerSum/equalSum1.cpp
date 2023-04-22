#include<bits/stdc++.h>
using namespace std;

// Appraoch 2 : Brute Force
// TC : O(N^2)  SC : O(N)

vector<long long> smallerSum(int n, vector<int> &arr) {
    vector<long long> ans; // vector to store answer
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(arr[j] < arr[i]) {
                sum += arr[j];
            }
        }
        ans.push_back(sum);  
    }
    return ans;
}

// Main Function
int main() {
    // Sample input 
    int n = 6;
    vector<int> arr = {4, 2, 6, 1, 5, 3};
    vector<long long> ans = smallerSum(n, arr);
    cout << "Sample Input: [4, 2, 6, 1, 5, 3]" << endl;
    cout << "Output: [";
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << "]" << endl << endl;
    
    return 0;
}
