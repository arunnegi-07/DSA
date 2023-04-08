#include<bits/stdc++.h>
using namespace std;

// Approach : Best and Efficient approach using Stack
// TC : O(size of array)  SC : O(size of array)

vector<int> makeBeautiful(vector<int> arr) {
    vector<int> ans; // vector to store beautiful array
    stack<int> st;   // Stack to keep track of elements 

    // Loop through the input vector `arr`
    for(int i=0;i<arr.size();i++){
        // If the stack is empty, push the current element to the stack
        if(st.empty()) st.push(arr[i]);
        // If the top of the stack is positive and the current element is zero,
        // or the top of the stack is zero and the current element is positive,
        // push the current element to the stack
        else if(st.top() >= 0 && arr[i] == 0 || st.top() == 0 && arr[i] >= 0) st.push(arr[i]); 
        // If the product of the top of the stack and the current element is negative,
        // pop the top of the stack
        else if(st.top() * arr[i] <= 0) st.pop();
        // Otherwise, push the current element to the stack
        else st.push(arr[i]);
    }

    // Pop elements from the stack and add them to the answer vector
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    // Reverse the 'ans' vector as elements are popped in reverse from the stack
    reverse(ans.begin(),ans.end());
    // return the 'ans' vector
    return ans;    
}

int main() {
    // Example 1
    vector<int> arr1 = {4, 2, -2, 1};
    vector<int> beautiful_arr1 = makeBeautiful(arr1);
    for (int i = 0; i < beautiful_arr1.size(); i++) {
        cout << beautiful_arr1[i] << " ";
    }
    cout << endl; // expected output: 4 1

    // Example 2
    vector<int> arr2 = {2, -2, 1, -1};
    vector<int> beautiful_arr2 = makeBeautiful(arr2);
    for (int i = 0; i < beautiful_arr2.size(); i++) {
        cout << beautiful_arr2[i] << " ";
    }
    cout << endl; // expected output: []

    // Example 3
    vector<int> arr3 = {-1, 2, -3, 4, -5, 6, -7};
    vector<int> beautiful_arr3 = makeBeautiful(arr3);
    for (int i = 0; i < beautiful_arr3.size(); i++) {
        cout << beautiful_arr3[i] << " ";
    }
    cout << endl; // expected output: -1, 2, -3, 4, -5, 6, -7

    return 0;
}
