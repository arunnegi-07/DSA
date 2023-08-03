// Naive Approach --> taking extra array space

// TC : O(N)  SC  : O(N + N)   --> 'N' for stack space and 'N' for extra space taken to store elements popped in recursive call

#include <bits/stdc++.h>
using namespace std;

// This helper function is used to reverse the elements of the stack by recursively
// popping elements from the original stack and storing them in a vector in reverse order.
// It takes a reference to the original stack 'St' and a reference to a vector 'v'
// where the elements will be stored in reverse order.
void helperReverse(stack<int> &St, vector<int> &v) {
    // Base case: If the stack is empty, there are no elements to reverse, so we return.
    if (St.empty())
        return;

    // Step 1: Store the top element of the stack in the vector.
    v.push_back(St.top());

    // Step 2: Pop the top element from the stack.
    St.pop();

    // Step 3: Recursively call the helperReverse function to process the remaining elements in the stack.
    helperReverse(St, v);
}

// This function reverses the elements in the original stack 'St'.
// It uses a helper function 'helperReverse' to reverse the elements and then
// pushes them back into the original stack in reverse order.
void Reverse(stack<int> &St) {
    // Step 1: Create an empty vector to store the elements temporarily.
    vector<int> v;

    // Step 2: Call the helper function 'helperReverse' to reverse the elements in the stack 'St'.
    helperReverse(St, v);

    // Step 3: The vector 'v' now contains the elements of the stack in reverse order.
    //         We iterate through the vector and push each element back into the original stack.
    for (int val : v) {
        St.push(val);
    }
}

int main() {
    // Sample Input 1
    stack<int> stack1;

    // Push some elements into the stack
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);

    cout << "Original Stack: ";
    stack<int> originalStack1 = stack1;
    while (!originalStack1.empty()) {
        cout << originalStack1.top() << " ";
        originalStack1.pop();
    }
    cout << endl;

    Reverse(stack1);

    cout << "Reversed Stack: ";
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;

    // Sample Input 2
    stack<int> stack2;

    // Push some elements into the stack
    stack2.push(100);
    stack2.push(200);
    stack2.push(300);

    cout << "Original Stack: ";
    stack<int> originalStack2 = stack2;
    while (!originalStack2.empty()) {
        cout << originalStack2.top() << " ";
        originalStack2.pop();
    }
    cout << endl;

    Reverse(stack2);

    cout << "Reversed Stack: ";
    while (!stack2.empty()) {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout << endl;

    return 0;
}