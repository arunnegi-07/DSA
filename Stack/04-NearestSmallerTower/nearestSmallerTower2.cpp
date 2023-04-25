// Approach 2 : Using Stack
// TC : O(N)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerTower(vector<int> arr){
    // vector to store value which is nearest smaller to the left for each element
    vector<int> left;  
    // vector to store value which is nearest smaller to the right for each element
    vector<int> right;
    // vector to store final answer
    vector<int> ans;
    // declared a stack
    stack<int> st;

    // traversing given array to find nearest smaller to the left
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            left.push_back(-1);
        }
        else{
            left.push_back(st.top());
        }

        st.push(i);
    }

    // making stack empty to reuse it
    while(!st.empty())
        st.pop();

    // traversing given array to find nearest smaller to the right
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            right.push_back(-1);
        }
        else{
            right.push_back(st.top());
        }

        st.push(i);
    }

    // while performing opeartions from end for right nearest smaller
    // elements has inserted in 'right' array in reverse order
    // so to get correct order reversing it.
    reverse(right.begin(),right.end());

    // using 'left' and 'right' to find nearest smaller from every point
    // beacause it may be either on 'left' or 'right' side
    for(int i=0;i<arr.size();i++){
        if(arr[left[i]] == -1 && arr[right[i]] == -1) ans.push_back(-1);
        else if(left[i] == -1) ans.push_back(right[i]);
        else if(right[i] == -1) ans.push_back(left[i]);
        else if(abs(i - left[i]) < abs(i - right[i])) ans.push_back(left[i]);
        else if(abs(i - left[i]) == abs(i - right[i])){
            if(arr[left[i]] <= arr[right[i]]) ans.push_back(left[i]);
            else ans.push_back(right[i]);
        } 
        else ans.push_back(right[i]);
    }
    
    // Giving this for dry-run purpose
    // for(auto i : left) cout << i << " "; cout << endl;
    // for(auto i : right) cout << i << " "; cout << endl;     

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
