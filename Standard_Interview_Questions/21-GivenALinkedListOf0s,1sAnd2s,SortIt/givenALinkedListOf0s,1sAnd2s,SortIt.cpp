// TC : O(N)  SC : O(1)  -->  As we are just using dummy node which is just O(1). 

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* segregate(Node* head) {
    // Initialize three pointers and dummy nodes for 0s, 1s, and 2s segments
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    // Create tails for each segment to easily append nodes at the end
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    // Traverse the linked list and segregate the nodes
    Node* current = head;
    while (current) {
        if (current->data == 0) {
            zeroTail->next = current;
            zeroTail = zeroTail->next;
        } else if (current->data == 1) {
            oneTail->next = current;
            oneTail = oneTail->next;
        } else {
            twoTail->next = current;
            twoTail = twoTail->next;
        }
        current = current->next;
    }

    // Connect the three segments together
    zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;

    // Update the head of the modified linked list
    head = zeroHead->next;

    // Set the next of the last node to nullptr to avoid loops in the linked list
    twoTail->next = nullptr;

    // Delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage:
int main() {
    // Create the linked list from the values array
    int values1[] = {1, 2, 2, 1, 2, 0, 2, 2};
    int n1 = sizeof(values1) / sizeof(values1[0]);

    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    for (int i = 0; i < n1; i++) {
        Node* newNode = new Node(values1[i]);
        if (!head1) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    std::cout << "Original List 1: ";
    printList(head1);

    // Segregate the linked list
    head1 = segregate(head1);

    std::cout << "Segregated List 1: ";
    printList(head1);

    // Clean up memory (don't forget to delete allocated nodes)
    Node* current = head1;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
