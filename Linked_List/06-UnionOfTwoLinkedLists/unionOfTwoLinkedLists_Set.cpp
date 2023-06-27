// Approach : Using Set DataStructure
// TC : O((N+M)*Log(N+M))   SC : O(N+M)
// Where, N and M are lengths of both linked lists respectively.

#include <iostream>
#include <set>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    set<int> uniqueElements;
    
    // Traverse the first and second linked lists
    while (head1 != NULL || head2 != NULL) {
        // Insert elements from the first linked list
        if (head1 != NULL) {
            uniqueElements.insert(head1->data);
            head1 = head1->next;
        }
        
        // Insert elements from the second linked list
        if (head2 != NULL) {
            uniqueElements.insert(head2->data);
            head2 = head2->next;
        }
    }
    
    // Create a dummy head for the result linked list
    Node* resultHead = new Node(0);
    Node* resultTail = resultHead;
    
    // Create a new linked list with the unique elements
    for (auto val : uniqueElements) {
        // Allocate memory for each node and assign the value
        Node* newNode = new Node(val);
        
        // Append the new node to the result linked list
        resultTail->next = newNode;
        resultTail = resultTail->next;
    }

    // Return the head of the result linked list (excluding the dummy head)
    return resultHead->next;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample inputs
    // Linked List 1: 9 -> 6 -> 4 -> 2 -> 3 -> 8
    Node* head1 = new Node(9);
    head1->next = new Node(6);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(3);
    head1->next->next->next->next->next = new Node(8);
    
    // Linked List 2: 1 -> 2 -> 8 -> 6 -> 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(6);
    head2->next->next->next->next = new Node(2);
    
    // Call the makeUnion function
    Node* result = makeUnion(head1, head2);
    
    // Print the result linked list
    cout << "Union List: ";
    printList(result);
    
    return 0;
}
