#include <bits/stdc++.h>
using namespace std;

// This function takes in an integer n, a vector arr, and a vector time,
// and returns the total time required to complete a task
int totalTime(int n, vector<int> &arr, vector<int> &time) {
    // Create a map to keep track of the occurrences of each element in arr
    map<int,int> mp;
    // Initialize the map with the first element of arr
    mp[arr[0]]++;
    // Initialize the answer variable to zero
    int ans=0;
    // Iterate through the rest of the elements in arr
    for(int i=1;i<n;i++){
        // If the element has already occurred before,
        if(mp[arr[i]]>0){
            // Add the time at the corresponding index in time vector to ans
            ans+=time[arr[i]-1];
        }
        // If the element has not occurred before,
        else{
            // Add 1 to ans,
            ans++;
            // and add the element to the map
            mp[arr[i]]++;
        }
    }
    // Return the total time required to complete the task
    return ans;
}

int main() {
    // Sample input 1:
    int n1 = 4;
    vector<int> arr1 = {1, 2, 3, 3};
    vector<int> time1 = {1, 2, 3, 4};
    cout << "output1: " << totalTime(n1, arr1, time1) << endl;
    cout << endl;
    
    // Sample input 2:
    int n2 = 4;
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> time2 = {1, 2, 3, 4};
    cout << "output2: " << totalTime(n2, arr2, time2) << endl;
    cout << endl;
   
    // Sample input 3:
    int n3 = 8;
    vector<int> arr3 = {6, 6, 1, 8, 1, 1, 3, 1};
    vector<int> time3 = {8, 4, 1, 5, 2, 8, 9, 3};
    cout << "output3: " << totalTime(n3, arr3, time3) << endl;
    cout << endl;
   
   
    

}