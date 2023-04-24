#include <bits/stdc++.h>
using namespace std;

vector<int> leftSmaller(int n, int a[]){
    // create an empty vector to store the answer
    vector<int> ans;
    // create an empty stack to store elements of the array
    stack<int> st;
    
    // traverse through the array
    for(int i=0;i<n;i++){
        // if stack is not empty and the top element is greater than or equal to the current
        // element of the array keep popping the elements from the stack. 
        while(!st.empty() && st.top() >= a[i]){
            st.pop();
        }
        
        // if the stack is empty after the above while loop, then there is no smaller element to the left of the current element
        if(st.empty()){
            ans.push_back(-1);
        }
        
        // else the smaller element to the left of the current element is the top element of the stack
        else{
            ans.push_back(st.top());
        }
        
        // push the current element to the stack
        st.push(a[i]);
    }
    
    // return the final answer
    return ans;
}

// sample inputs and main function
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> result = leftSmaller(n, a);
    cout << "The smaller elements to the left of each element in the array are: ";
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

