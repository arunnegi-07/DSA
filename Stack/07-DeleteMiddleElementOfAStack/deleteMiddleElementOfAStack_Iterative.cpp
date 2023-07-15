// Approach 2 : Iterative Method --> Taking Auxilliary Stack
// TC : O(N)  SC : O(N) 

// Appraoch 1 : Recursive Method
// TC : O(N)  SC : O(N)  --> Stack Space

#include <iostream>
#include <stack>
using namespace std;

    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int half = sizeOfStack / 2;
        stack<int> auxiSt;
        
        
        //Step 1 : shifting first half values to auxilliary stack
        while(half--){
            int val = s.top();
            auxiSt.push(val);
            s.pop();
        }
    
        // Step 2 : Removing Mid element
        s.pop();
        
        // Step 3 : shifting back elements to original stack
        while(!auxiSt.empty()){
            int val = auxiSt.top();
            s.push(val);
            auxiSt.pop();
        }
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
