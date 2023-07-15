// Appraoch 1 : Recursive Method
// TC : O(N)  SC : O(N)  --> Stack Space

#include <iostream>
#include <stack>
using namespace std;

// Function to delete the middle element of a stack
void deleteUtil(stack<int>& s, int mid){
    // Base case: If the size of the stack is equal to the middle index,
    // pop the element and return
    if (s.size() == mid) {
        s.pop();
        return;
    }

    // Remove the top element from the stack and store it
    int topVal = s.top();
    s.pop();

    // Recursive call to delete the middle element
    deleteUtil(s, mid);

    // Push back the top element after the recursive call
    s.push(topVal);        
}

void deleteMid(stack<int>& s, int sizeOfStack) {
    // Calculate the index of the middle element
    int mid;
    if (sizeOfStack % 2 == 1) {
        // If the size is odd, set mid to (sizeOfStack / 2) + 1
        mid = sizeOfStack / 2 + 1;
    } else {
        // If the size is even, set mid to sizeOfStack / 2
        mid = sizeOfStack / 2;
    }

    // Call the deleteUtil function to delete the middle element
    deleteUtil(s, mid);
}

int main() {
    // Sample Input 1
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    
    // Create a copy of stack1 for display purposes
    stack<int> tempSt = stack1;
    int size1 = tempSt.size();
    
    cout << "Stack 1 Before Deletion: ";
    while (!tempSt.empty()) {
        cout << tempSt.top() << " ";
        tempSt.pop();
    }
    cout << endl;

    // Delete the middle element from Stack 1
    deleteMid(stack1, size1);

    cout << "Stack 1 After Deletion: ";
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;

    // Sample Input 2
    stack<int> stack2;
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);
    
    // Create a copy of stack2 for display purposes
    tempSt = stack2;
    int size2 = tempSt.size();
    
    cout << "Stack 2 Before Deletion: ";
    while (!tempSt.empty()) {
        cout << tempSt.top() << " ";
        tempSt.pop();
    }
    cout << endl;

    // Delete the middle element from Stack 2
    deleteMid(stack2, size2);

    cout << "Stack 2 After Deletion: ";
    while (!stack2.empty()) {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout << endl;

    return 0;
}
