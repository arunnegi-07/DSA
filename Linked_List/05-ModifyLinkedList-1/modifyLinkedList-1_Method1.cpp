// TC : O(5N) ≈ O(N)  SC : O(1)

#include <stdio.h>
#include <stdlib.h>

// Linked List Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the Linked List
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to modify the Linked List
struct Node *modifyTheList(struct Node *head){
    // Step 1: Placing a pointer to the end

    Node *last = head;
    while (last->next){
        last = last->next;
    }

    // Step 2: Finding mid node:

    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;

    // making unnecessary pointer free
    slow = NULL; free(slow);
    fast = NULL; free(fast);

    // Step 3: Reversing references of 2nd half of Linked List
    //         so that it become easy for us to traverse back from 'last' as it is not possible in Singly Linked list

    Node *curr = mid, *front = NULL, *back = NULL;

    while (curr != NULL){
        back = curr->next;
        curr->next = front;
        front = curr;
        curr = back;
    }

    // Step 4: Performing Calculations

    Node *begin = head, *end = last;
    while (begin || end){
        int temp = begin->data;
        begin->data = end->data - begin->data;
        end->data = temp;

        if (end->next == begin)
            break; // to handle even length list

        begin = begin->next;
        end = end->next;
    }

    // making unnecessary pointer free
    begin = NULL; free(begin);
    end = NULL; free(end);

    // Step 5: Reversing back the references of 2nd half of Linked list

    curr = last, front = NULL, back = NULL;
    while (curr != NULL){
        back = curr->next;
        curr->next = front;
        front = curr;
        curr = back;
    }

    // making unnecessary pointer free
    curr = NULL; free(curr);
    front = NULL; free(front);
    back = NULL; free(back);

    // Finally returning Modified Linked List
    return head;
}

int main() {
    // Create the Linked List
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    // Modify the Linked List
    head = modifyTheList(head);

    printf("Modified List: ");
    printList(head);

    // Freeing the memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
