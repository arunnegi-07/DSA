// TC : O(N*logN)  SC : O(N)

#include<bits/stdc++.h>
using namespace std;

// Define the structure of a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// This function performs an in-order traversal of a binary tree and stores
// the elements in the 'inorder' vector.
void inorderTraversal(Node *root, vector<int> &inorder) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorderTraversal(root->left, inorder);

    // Add the current node's data to the 'inorder' vector
    inorder.push_back(root->data);

    // Traverse the right subtree
    inorderTraversal(root->right, inorder);
}

// This function converts a binary tree to a Binary Search Tree (BST) using
// the elements stored in the 'inorder' vector. It updates the tree nodes
// in-place.
void binaryToBST(Node *root, vector<int> &inorder, int &index) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    binaryToBST(root->left, inorder, index);

    // Update the current node's data with the next element from 'inorder' vector
    root->data = inorder[index++];

    // Traverse the right subtree
    binaryToBST(root->right, inorder, index);
}

// This function converts a binary tree to a Binary Search Tree (BST).
Node *binaryTreeToBST(Node *root) {
    // Create a vector to store the elements of the binary tree in sorted order.
    vector<int> inorder;

    // Step 1 : Perform an in-order traversal to populate the 'inorder' vector.
    inorderTraversal(root, inorder);

    // Step 2 : Sort the 'inorder' vector to obtain the elements in ascending order.
    sort(inorder.begin(), inorder.end());

    // Initialize an index variable to keep track of the current element in 'inorder'.
    int index = 0;
    // Step 3 : Convert the binary tree to a BST by updating the nodes' data values.
    binaryToBST(root, inorder, index);

    // Return the root of the resulting BST.
    return root;
}

int main() {
    // Sample binary tree 1
    Node *root1 = new Node();
    root1->data = 4;
    root1->left = new Node();
    root1->left->data = 2;
    root1->left->left = new Node();
    root1->left->left->data = 1;
    root1->left->right = new Node();
    root1->left->right->data = 3;
    root1->right = new Node();
    root1->right->data = 6;
    root1->right->left = new Node();
    root1->right->left->data = 5;
    root1->right->right = new Node();
    root1->right->right->data = 7;

    // Sample binary tree 2
    Node *root2 = new Node();
    root2->data = 3;
    root2->left = new Node();
    root2->left->data = 2;
    root2->left->left = new Node();
    root2->left->left->data = 1;
    root2->right = new Node();
    root2->right->data = 4;

    // Convert binary tree 1 to a BST
    Node *bst1 = binaryTreeToBST(root1);

    // Convert binary tree 2 to a BST
    Node *bst2 = binaryTreeToBST(root2);

    // Display the converted BSTs (inorder traversal)
    cout << "Inorder traversal of BST 1: ";
    vector<int> inorder1;
    inorderTraversal(bst1, inorder1);
    for (int val : inorder1) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal of BST 2: ";
    vector<int> inorder2;
    inorderTraversal(bst2, inorder2);
    for (int val : inorder2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
