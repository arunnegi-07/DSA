#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Approach : Using Hashing
// TC : O(N)  SC : O(N)

//Function to detect cycle
bool detectLoop(Node* head) {
    // Using unordered Set to store 'head' of nodes explored 
    unordered_set<Node*> hashTable;
    while(head != NULL) {
        // if current 'head' is already present in the hashTable then loop exists, return true
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    // if loop ended with being returned means no cycle present;
    return false;
}

// Approach : Using Slow and Fast Pointer
// TC : O(N)  SC : O(1)

//Function to check if the linked list has a cycle.
bool detectLoop(Node *head){

    // base case: empty list
    if(!head) return false;

    // detect the cycle using Floyd's cycle-finding algorithm
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    // if fast and slow are not equal (or) fast is null (or) fast->next is null, then there is no loop
    // !fast is helpful when only one node is present because at that time loop will break in starting itself
    // and that time slow will remain equal to fast.
    if(slow != fast || !fast -> next) return false;  
    else return true;
}

// Sample inputs
// Linked List without a loop
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Node* input1() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    return head;
}

// Linked List with a loop
// 1 -> 2 -> 3 -> 4 -> 5 -> 2
Node* input2() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;
    return head;
}

// Main function to test the detectLoop function with sample inputs
int main() {
    // Test case 1: Linked List without a loop
    Node* head1 = input1();
    cout << "Test Case 1: Linked List without a loop" << endl;
    if (detectLoop(head1)) {
        cout << "The Linked List has a loop" << endl;
    } else {
        cout << "The Linked List does not have a loop" << endl;
    }

    // Test case 2: Linked List with a loop
    Node* head2 = input2();
    cout << "Test Case 2: Linked List with a loop" << endl;
    if (detectLoop(head2)) {
        cout << "The Linked List has a loop" << endl;
    } else {
        cout << "The Linked List does not have a loop" << endl;
    }

    return 0;
}
