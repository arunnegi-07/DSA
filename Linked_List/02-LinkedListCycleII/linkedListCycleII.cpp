#include<iostream>
using namespace std;

struct Node {
    int val; // data value of the node
    Node *next; // pointer to next node
    Node() : val(0), next(nullptr) {} // constructor to initialize values
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};
typedef struct Node Node;

void print(Node *head){
    Node *ptr = head;
    while(ptr){
        cout << ptr -> val << " "; // print the data value of the node
        ptr = ptr -> next; // move to next node
    }
}

void addNode(int val,Node* &tail){
    tail -> next = new Node(val); // add new node to the end of linked list
    tail = tail -> next; // update the tail to point to the last node
}

// Approach : Using Slow and Fast Pointer
// TC : O(N)  SC : O(1)

//Function to check if the linked list has a cycle.
Node* detectCycle(Node *head){
    // base case
    if(!head) return NULL; // if linked list is empty, return null

    // detect the cycle using Floyd's cycle-finding algorithm
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next; // move slow pointer by one step
        fast = fast->next->next; // move fast pointer by two steps
        if (slow == fast) { // if both pointers meet, break from the loop
            break;
        }
    }
    if(slow!=fast || !fast -> next) return NULL; // if loop is not found, return null
    
    // finding entry point
    if (slow == fast) { // if loop is found
        slow = head; // set slow pointer to head of the linked list
        
        // this check is needed when slow and fast both meet at the head of the LL
        if (slow == fast) 
            return head; // if the loop starts at head, return head
        else{
            while (slow != fast) { // move both pointers by one step until they meet at the entry point
                slow = slow->next;
                fast = fast->next;
            } 
        } 
    }
    return slow; // return the entry point of the loop
}

int main(){
    // creating a List containing cycle
    Node *head = NULL, *tail = NULL;
    head = new Node(1); // create the head node
    tail = head; // set the tail to point to head
    addNode(2,tail);
    addNode(0,tail);
    addNode(4,tail);
    addNode(5,tail);
    addNode(6,tail);
    addNode(7,tail);
    addNode(8,tail);
    addNode(9,tail);
    tail -> next = head; // create a loop by making the last node point to the head
    
    Node* res = detectCycle(head); // detect the entry point of the loop
    
    res != NULL ? cout << "Entry point is at Node: " << res -> val : cout << "Cycle is not present"; // print the result
    
    return 0;      
} 
