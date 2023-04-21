#include <bits/stdc++.h>
using namespace std;

// Approach 2 : Better and clean code then Approach 1
// TC : O(N) in worst case   SC : O(Height of Tree) in worst case

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to check whether a binary tree is a valid binary search tree
bool ValidBST(Node* root, Node* min, Node* max) {
    if (root == NULL) {
        // If the root is NULL, it is a valid BST
        return true;
    }

    if (min != NULL && root->data <= min->data) {
        // If the root's value is less than or equal to the minimum value seen so far,
        // it is not a valid BST
        return false;
    }

    if (max != NULL && root->data >= max->data) {
        // If the root's value is greater than or equal to the maximum value seen so far,
        // it is not a valid BST
        return false;
    }

    // Recursively check the left and right subtrees
    bool left = ValidBST(root->left, min, root);
    bool right = ValidBST(root->right, root, max);

    // If both subtrees are valid BSTs, the entire tree is a valid BST
    return left && right;
}

bool isBST(Node* root) 
{   
    // setting min and max to NULL intially, these are used to check parent is greater than left child and
    // smaller than right child, which is the property of BST
    Node *min = NULL,*max = NULL;

    // calling helper function to check if given tree is BST or not
    return ValidBST(root,min,max);
}

// Function to create a sample binary tree 1
Node* createSampleTree() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    return root;
}

// Function to create sample binary tree 2
Node* createAnotherSampleTree() {
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(6);
    return root;
}

// Main function to run the program
int main() {
    Node* tree1 = createSampleTree();
    Node* tree2 = createAnotherSampleTree();

    cout << "Sample Tree 1:\n";
    if (isBST(tree1)) {
        cout << "Valid BST\n";
    } else {
        cout << "Not a valid BST\n";
    }

    cout << "\nSample Tree 2:\n";
    if (isBST(tree2)) {
        cout << "Valid BST\n";
    } else {
        cout << "Not a valid BST\n";
    }

    return 0;
}
