/* Approach 1 : Using HashMap 
   TC : O(N)  SC : O(N)
   
   In this approach we first calculate the parents for each nodes present in the
   tree, for storing parents for corresponding nodes we will use 'Unordered Map'
   because while retrieving back the parent the complexity will be O(1).
   
   After that we simply traverse 'k' times for given 'node' and we get our Kth ancestor.
   
                                                                                                                                                                                                                                                                                                                                */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to populate the parent map for each node in the binary tree
void populateParentMap(Node* root, int parent,unordered_map<int, int>& parentMap) {
    if (!root) {
        return;
    }
    
    // Store the parent of the current node in the parentMap
    parentMap[root->data] = parent;
    
    // Recursively populate the parentMap for the left subtree
    populateParentMap(root->left, root->data, parentMap);
    
    // Recursively populate the parentMap for the right subtree
    populateParentMap(root->right, root->data, parentMap);
}

// Function to find the kth ancestor of a node in a binary tree
int kthAncestor(Node* root, int k, int nodeData) {
    if (!root) {
        return -1;
    }

    // Create a map to store the parent of each node
    unordered_map<int, int> parentMap;
    
    // Populate the parentMap with the parent of each node
    populateParentMap(root, -1, parentMap);

    // Traverse up the ancestor path until either k becomes 0 or the node is not found
    while (parentMap.find(nodeData) != parentMap.end() && k > 0) {
        nodeData = parentMap[nodeData];
        --k;
    }

    // If the node is not found in the ancestor path, return -1; otherwise, return the kth ancestor
    return parentMap.find(nodeData) == parentMap.end() ? -1 : nodeData;
}

int main() {
    // Sample binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //   /
    //  8

    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    int k = 2; // Find 2nd ancestor
    int nodeData = 4; // Find the ancestor of node with data 4

    // Find the kth ancestor of the given node
    int kthAncestorValue = kthAncestor(root, k, nodeData);

    // Print the kth ancestor value
    if (kthAncestorValue != -1) {
        std::cout << "Kth ancestor of node " << nodeData << " is: " << kthAncestorValue << std::endl;
    } else {
        std::cout << "Kth ancestor not found!" << std::endl;
    }

    return 0;
}
