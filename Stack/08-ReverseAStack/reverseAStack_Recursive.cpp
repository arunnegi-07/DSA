// Using only Recusion, not taking that array space.
// TC : O(N)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int element) {
    // If the stack is empty, simply push the element onto the stack and return.
    if (st.empty()) {
        st.push(element);
        return;
    }

    // Step 1: Remove the top element from the stack and store it in a variable.
    int topElement = st.top();
    st.pop();

    // Step 2: Recursively call the insertAtBottom function with the remaining stack and the element to be inserted.
    insertAtBottom(st, element);

    // Step 3: After the recursive call returns, push the stored top element back onto the stack.
    st.push(topElement);
}

// Function to reverse the given stack using recursion
void Reverse(stack<int>& st) {
    // If the stack is empty, there are no elements to reverse, so we simply return.
    if (st.empty()) {
        return;
    }

    // Step 1: Remove the top element from the stack and store it in a variable.
    int topElement = st.top();
    st.pop();

    // Step 2: Recursively call the Reverse function with the remaining stack.
    Reverse(st);

    // Step 3: After the recursive call returns, we have the stack reversed from the top.
    // Now, we need to insert the stored top element at the bottom of the reversed stack.
    insertAtBottom(st, topElement);
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