// Appaoch 1 : Naive Method 
// TC : O(N)  SC : O(N)


#include <iostream>
#include <vector>
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal of the BST and store node values in a vector
void inOrder(Node* root, vector<Node*>& sortedNodes) {
    if (root == nullptr)
        return;

    // Recursively traverse the left subtree
    inOrder(root->left, sortedNodes);
    
    // Push the current node into the sortedNodes vector (inorder traversal gives sorted order)
    sortedNodes.push_back(root);
    
    // Recursively traverse the right subtree
    inOrder(root->right, sortedNodes);
}

// Function to find the Inorder Successor of a given node in the BST
Node* inOrderSuccessor(Node* root, Node* x) {
    // Create an empty vector to store the nodes in sorted order
    vector<Node*> sortedNodes;
    // Perform inorder traversal to populate the sortedNodes vector
    inOrder(root, sortedNodes);
        
    // Initialize a pointer to store the answer (inorder successor)
    Node* ans = nullptr;
    int n = sortedNodes.size();
    
    // Find the node x in the sortedNodes vector
    for (int i = 0; i < n - 1; i++) {
        if (sortedNodes[i]->data == x->data) {
            // If x is found, set the answer to the next node in the sortedNodes vector
            ans = sortedNodes[i + 1];
            break;
        }
    }
    return ans;
}

// Helper function to insert nodes in the BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Sample main function to demonstrate the usage of the inOrderSuccessor function
int main() {
    // Sample BST - Example 1
    Node* root1 = nullptr;
    root1 = insert(root1, 2);
    root1 = insert(root1, 1);
    root1 = insert(root1, 3);
    
    Node* x1 = root1->left; // Node with data 1
    Node* result1 = inOrderSuccessor(root1, x1);
    if (result1)
        cout << "Inorder successor of " << x1->data << " is " << result1->data << endl;
    else
        cout << x1->data << " does not have an inorder successor." << endl;

    // Sample BST - Example 2
    Node* root2 = nullptr;
    root2 = insert(root2, 20);
    root2 = insert(root2, 8);
    root2 = insert(root2, 22);
    root2 = insert(root2, 4);
    root2 = insert(root2, 12);
    root2 = insert(root2, 10);
    root2 = insert(root2, 14);
    
    Node* x2 = root2->left; // Node with data 8
    Node* result2 = inOrderSuccessor(root2, x2);
    if (result2)
        cout << "Inorder successor of " << x2->data << " is " << result2->data << endl;
    else
        cout << x2->data << " does not have an inorder successor." << endl;

    return 0;
}
