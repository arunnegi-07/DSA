/* TC : O(1)  SC : O(1)
     
    This Problem very simple, we just implementing push() and pop() function for a 'stack' data structure.
    According to problem, we are using an array 'arr' to implement 'twoStacks' in which both array will take
    half part of the array.
    'stack1' will push and pop elements from front of the array using 'top1' set initially to '-1', and 
    'stack2' will push and pop elements from back of the array using 'top2' set initially to 'size'.
    
    So, we are just pushing and popping the elements according to stack properties and returning the value for every pop()
    operation on any stack and printing it.
                                                                                                                                                                                                                                                                                                        */
                                                                                                                                                                                                                                                                                                        
#include <iostream>
using namespace std;

class twoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into stack1.
    void push1(int x) {
        arr[++top1] = x;
    }

    // Function to push an integer into stack2.
    void push2(int x) {
        arr[--top2] = x;
    }

    // Function to remove an element from the top of stack1.
    int pop1() {
        if (top1 == -1)
            return -1;
        return arr[top1--];
    }

    // Function to remove an element from the top of stack2.
    int pop2() {
        if (top2 == size)
            return -1;
        return arr[top2++];
    }
};

int main() {
    // Create an instance of the twoStacks class
    twoStacks ts(6);

    // Pushing elements into the stacks
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);

    // Pop elements from the stacks and print the results
    cout << ts.pop1() << " ";  // Output: 3
    cout << ts.pop2() << " ";  // Output: 4
    cout << ts.pop2() << " ";  // Output: -1 (stack2 is empty)

    cout << endl;

    // Pushing and popping elements from both stacks
    ts.push1(1);
    ts.push2(2);
    cout << ts.pop1() << " ";  // Output: 1
    ts.push1(3);
    cout << ts.pop1() << " ";  // Output: 3
    cout << ts.pop1() << " ";  // Output: -1 (stack1 is empty)

    return 0;
}
