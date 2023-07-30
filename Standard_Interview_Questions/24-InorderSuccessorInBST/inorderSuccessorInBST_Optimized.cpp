// Approach 2 : Optimized --> Used property of BST 
// TC : O(N)  SC : O(1)
    
                                                                        
#include <iostream>                                
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the Inorder Successor of a given node in the BST
Node* inOrderSuccessor(Node* root, Node* x) {
    // Initialize two pointers, 'curr' and 'ans', to traverse the BST
    Node* curr = root;
    Node* ans = NULL;

    // Traverse the BST until curr becomes NULL (i.e., we reach a leaf node or x is not present in the BST)
    while (curr != NULL) {
        // If the current node's value is greater than the value of the given node 'x'
        if (curr->data > x->data) {
            // Update 'ans' to the current node because it could be a potential successor
            ans = curr;
            // Move to the left child as the potential successor will be in the left subtree
            curr = curr->left;
        } else {
            // If the current node's value is less than or equal to the value of 'x',
            // move to the right child as the potential successor (if any) will be in the right subtree
            curr = curr->right;
        }
    }

    // 'ans' will contain the inorder successor of 'x' (if it exists) after the while loop finishes
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
