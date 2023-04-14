#include<bits/stdc++.h>
using namespace std;

// The function returns an integer, representing the number of remaining balls
// after removing all pairs of balls with the same color and radius.

int finLength(int N, vector<int> color, vector<int> radius) {
    // Create a stack of pairs of integers to keep track of the balls.
    stack<pair<int,int>> st;

    // Iterate through all the balls.
    for(int i = 0; i < N; i++) {
        // If the top ball on the stack has the same color and radius as the current ball,
        // remove the top ball from the stack.
        if(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
            st.pop();
        } else {
            // Otherwise, add the current ball to the stack.
            st.push({color[i],radius[i]});
        }
    }

    // Return the number of remaining balls on the stack.
    return st.size();
}

int main() {
    vector<int> color1 = {1, 1, 2, 2, 2, 3, 3};
    vector<int> radius1 = {2, 2, 3, 3, 3, 4, 4};
    cout << finLength(7, color1, radius1) << endl; // Output: 1

    vector<int> color2 = {1, 2, 3, 4, 5};
    vector<int> radius2 = {1, 2, 3, 4, 5};
    cout << finLength(5, color2, radius2) << endl; // Output: 5

    vector<int> color3 = {1, 1, 1, 2, 2, 2};
    vector<int> radius3 = {1, 1, 1, 2, 2, 2};
    cout << finLength(6, color3, radius3) << endl; // Output: 2
    return 0;
}
