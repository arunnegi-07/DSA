// TC : O(Height of the BST)   SC : O(Height of the BST).

#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node with the given data
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a new node with data into the BST
Node* insert(Node* node, int data) { 
    // If the current node is null, create a new node with the given data
    if (node == NULL) {
        return new Node(data);
    } 
    // If the data is less than the current node's data, insert into the left subtree
    else if (data < node->data) {
        node->left = insert(node->left, data);
    } 
    // If the data is greater than the current node's data, insert into the right subtree
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // If the data is equal to the current node's data, no action is needed (no duplicates)
    
    // Return the current node (with or without modifications)
    return node;
}

// Inorder traversal to print the tree nodes in sorted order
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    // Sample input 1
    Node* root1 = NULL;
    int values1[] = {2, 1, 3, 4};
    for (int val : values1) {
        root1 = insert(root1, val);
    }
    
    cout << "Inorder traversal of BST 1: ";
    inorder(root1);
    cout << endl;

    // Sample input 2
    Node* root2 = NULL;
    int values2[] = {5, 2, 7, 2, 6, 8};
    for (int val : values2) {
        root2 = insert(root2, val);
    }
    
    cout << "Inorder traversal of BST 2: ";
    inorder(root2);
    cout << endl;

    return 0;
}
