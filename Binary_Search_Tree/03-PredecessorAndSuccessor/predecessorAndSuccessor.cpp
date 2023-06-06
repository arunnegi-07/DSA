// TC : O(Height of BST)  SC : O(Height of BST)   

#include <iostream>
using namespace std;

// Node structure for BST
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

// This class contains the function to find the predecessor and successor of a given key in BST
class Solution {
public:
    // Function to find the predecessor and successor
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (root) {
            // Traverse the left subtree recursively
            findPreSuc(root->left, pre, suc, key);

            // Check if the current node's key is less than the given key
            // If so, update the predecessor to the current node
            if (root->key < key)
                pre = root;

            // Check if the current node's key is greater than the given key
            // and the successor is not set yet (initially set to nullptr)
            // If so, update the successor to the current node
            if (root->key > key && suc == nullptr)
                suc = root;

            // Traverse the right subtree recursively
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

// Sample inputs:
// Input 1: A binary search tree with nodes containing integer keys
//          key = 5
//          4
//         / \
//        2   6
//       / \
//      1   3
//
// Input 2: A binary search tree with nodes containing character keys (alphabetical order)
//          key = 'G'
//           F
//          / \
//         D   H
//        / \   \
//       B   E   J
//        \
//         C

int main() {
    // Create a binary search tree and initialize it with nodes and keys

    // Example 1:
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);

    Node* pre1 = nullptr;
    Node* suc1 = nullptr;
    int key1 = 5;

    Solution sol1;
    sol1.findPreSuc(root1, pre1, suc1, key1);

    cout << "Predecessor of " << key1 << ": " << (pre1 ? pre1->key : -1) << endl;
    cout << "Successor of " << key1 << ": " << (suc1 ? suc1->key : -1) << endl;

    // Example 2:
    Node* root2 = new Node('F');
    root2->left = new Node('D');
    root2->right = new Node('H');
    root2->left->left = new Node('B');
    root2->left->right = new Node('E');
    root2->left->left->right = new Node('C');
    root2->right->right = new Node('J');

    Node* pre2 = nullptr;
    Node* suc2 = nullptr;
    char key2 = 'G';

    Solution sol2;
    sol2.findPreSuc(root2, pre2, suc2, key2);

    cout << "Predecessor of " << key2 << ": " << (pre2 ? (char)pre2->key : '\0') << endl;
    cout << "Successor of " << key2 << ": " << (suc2 ? (char)suc2->key : '\0') << endl;

    return 0;
}
