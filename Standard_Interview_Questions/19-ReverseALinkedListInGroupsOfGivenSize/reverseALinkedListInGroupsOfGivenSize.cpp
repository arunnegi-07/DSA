/* TC : O(N)  SC : O(1)  --> Because performing operation on same Linked list, just using a one dummy node

    The problem is good and interesting, just a variation of reversing a linked list. Base for this problem is also reversing of a linked list
    just a simple difference is now we have to perform it in group of sizes 'k'.

    So, Approach we will follow is that we will take a 'dummy' node and then after reversing each group we will keep on attaching that
    part to that 'dummy' node and after completing all the groups we will return that 'dummy' node.

    Note : Read the given solution below carefully, it is well commented and explains each step.
                                                                                                                                                                                                                                                                                                                    */
                                                                                                                                                                                                                                                                                                                    
#include <iostream>

struct node {
    int data;
    node* next;
    node(int value) : data(value), next(nullptr) {}
};

// Function to print the linked list
void printLinkedList(node* head) {
    node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to free the memory allocated for the linked list
void deleteLinkedList(node* head) {
    node* current = head;
    while (current != nullptr) {
        node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Function to reverse the linked list in groups of size 'k'
struct node *reverse (struct node *head, int k)
{ 
    // creating dummy node 
    node *ans = new node(0);
    node *tail = ans;
    
    // making copy of given value of 'k'
    int temp = k;
    
    
    // Now, reversing given list in group of sizes 'k'
    // So, here are using that same algorithm of reversing a linked list, just 
    // simple difference is that we are now doing it in groups.
    node* prev = nullptr;
    node* curr = head;
    node* nextNode = nullptr;
    
    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        
        k--;
        
        // if group is completed we are adding that reversed part to 'answer' list
        if(k == 0){
            // this two lines are linking that group
            tail -> next = prev;
            tail = head;
            
            // updating head to start of new group
            head = nextNode;
            
            // also updating all the pointers as it is a new start of reversing new group                
            prev = nullptr;
            curr = head;
            nextNode = nullptr;
            
            // also updating value of 'k' back to it's initial value
            k = temp;
        }
    }

    // if last last group does not contain exactly 'k' nodes, in that case those nodes are
    // not attached to the answer, so attaching them also
    if(k != temp){
        head = curr;
        tail -> next = prev;
        tail = head;
    }
    
    // finally returning our answer list
    // ans -> next because while defining it extra '0' node was attached initially
    return ans -> next;
 }


int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);

    std::cout << "Original Linked List 1: ";
    printLinkedList(head1);

    int k1 = 3;
    node* reversedHead1 = reverse(head1, k1);

    std::cout << "Reversed Linked List 1: ";
    printLinkedList(reversedHead1);

    deleteLinkedList(reversedHead1);

    // Creating the linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> nullptr
    node* head2 = new node(10);
    head2->next = new node(20);
    head2->next->next = new node(30);
    head2->next->next->next = new node(40);
    head2->next->next->next->next = new node(50);
    head2->next->next->next->next->next = new node(60);
    head2->next->next->next->next->next->next = new node(70);

    std::cout << "Original Linked List 2: ";
    printLinkedList(head2);

    int k2 = 4;
    node* reversedHead2 = reverse(head2, k2);

    std::cout << "Reversed Linked List 2: ";
    printLinkedList(reversedHead2);

    deleteLinkedList(reversedHead2);

    return 0;
}
