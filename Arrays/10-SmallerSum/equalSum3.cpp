#include<bits/stdc++.h>
using namespace std;

// Appraoch 3 : Using Binary Search  
// TC : O(NlogN)  SC : O(N)

vector<long long> smallerSum(int n, vector<int> &arr) {
    map<int ,long long> mp; // frequency of every element
    unordered_map<int ,long long> Presum; // Prefix sum till every element
    
    // storing frequency of each element
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    
    // variable to store previous sum 
    long long prevsum = 0;
    for(auto it:mp)
    {   
        // storing prefix sum for values in 'mp' map and for first element in the ordered map 'mp' it will be zero 
        // as it is the smallest value among all and no value will be smaller than it
        Presum[it.first] = prevsum;   
        prevsum += it.second*it.first;  // previous Sum will be incremented by "current value * it's frequency" --> it's Sum
    }

    // finally to get our answer in same order as the given array
    // we simply iterate over the given array and by seeeing each value to push_back corresponding sum to the 'ans' vector 
    vector<long long> ans;
    for(int i=0;i<n;i++)
        ans.push_back(Presum[arr[i]]);
    
    // returning answer vector
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
