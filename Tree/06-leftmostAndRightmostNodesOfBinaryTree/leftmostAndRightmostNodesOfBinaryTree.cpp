// TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to print the corner nodes of a binary tree level by level
void printCorner(Node *root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Get the number of nodes at the current level
        
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            // Check if the current node is at the corner positions (leftmost or rightmost)
            if (i == 0 || i == size - 1) {
                cout << current->data << " ";
            }

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
    }
}

int main() {
    // Create a sample binary tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    // Print the corner nodes of the first sample binary tree
    cout << "Corner nodes of the first binary tree: ";
    printCorner(root1);
    cout << endl;

    // Create another sample binary tree
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    root2->left->left = new Node(40);
    root2->left->right = new Node(50);
    root2->right->left = new Node(60);

    // Print the corner nodes of the second sample binary tree
    cout << "Corner nodes of the second binary tree: ";
    printCorner(root2);
    cout << endl;

    return 0;
}
