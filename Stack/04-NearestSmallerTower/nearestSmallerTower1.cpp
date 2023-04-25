// Approach 2 : Brute Force
// TC : O(N^2)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerTower(vector<int> arr){
    // vector to store final answer
    vector<int> ans;

    // traversing given array to find nearest smaller to the left
    for(int i=0;i<arr.size();i++){
        int left_min_index = -1, right_min_index = -1;
        
        // traversing to left from point 'i' once we found smaller element than arr[i]
        // we will break as that will be the nearest smaller
        for(int j = i-1;j>=0;j--)
            if(arr[j] < arr[i]){left_min_index = j; break;}
         
        // traversing to right from point 'i' once we found smaller element than arr[i]
        // we will break as that will be the nearest smaller
        for(int j = i+1;j<arr.size();j++)
            if(arr[j] < arr[i]){right_min_index = j; break;}
        
        // now from both left and right side we will select the value which 
        // is smaller as well as the nearest.If both are at the same distance we will
        // choose the smaller one and if values are also same then we will select value
        // with lower index.
        if(arr[left_min_index] == -1 && arr[right_min_index] == -1) ans.push_back(-1);
        else if(left_min_index == -1) ans.push_back(right_min_index);
        else if(right_min_index == -1) ans.push_back(left_min_index);
        else if(abs(i - left_min_index) < abs(i - right_min_index)) ans.push_back(left_min_index);
        else if(abs(i - left_min_index) == abs(i - right_min_index)){
            if(arr[left_min_index] <= arr[right_min_index]) ans.push_back(left_min_index);
            else ans.push_back(right_min_index);
        } 
        else ans.push_back(right_min_index);
    }

    // finally returning final answer
    return ans;
}

int main() {
    vector<int> arr1 = {3, 5, 2, 4, 5};
    vector<int> ans1 = nearestSmallerTower(arr1);
    cout << "Answer for arr1: ";
    for(int x: ans1) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> ans2 = nearestSmallerTower(arr2);
    cout << "Answer for arr2: ";
    for(int x: ans2) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> ans3 = nearestSmallerTower(arr3);
    cout << "Answer for arr3: ";
    for(int x: ans3) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
