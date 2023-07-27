/* Approach 2 : Optimized --> Not taking extra space here to store parents in advance
   TC : O(N)  SC : O(N) --> Recursive calls stack space
   
   In this approach we keep on traversing the 'left' and 'right' side of the tree and return '-1' if given
   is not found, and if we got the given 'node' then we will check which side has returned the '-1' because
   it will give us proper idea like which side is that node is present.
   Depending upon which side the node is present we will add '1' to the distance we are calculating and 
   as soon as the distance become equal to 'k' we store that node to 'ans' variable. 
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

// Helper function to find the kth ancestor of the given node
int findKthAncestor(Node* root, int k, int nodeData, int* ancestorData) {
    // Base case: If the root is null, return -1 (indicating the node is not found).
    if (!root)
        return -1;

    // If the current node is the target node, return 0 to indicate its distance from itself.
    if (root->data == nodeData)
        return 0;

    // Recursively search in the left and right subtrees for the target node.
    int leftDistance = findKthAncestor(root->left, k, nodeData, ancestorData);
    int rightDistance = findKthAncestor(root->right, k, nodeData, ancestorData);

    // Check if the target node is found in the left or right subtree.
    if (leftDistance != -1 && rightDistance == -1) {
        // If the node is found in the left subtree and its distance from the target node plus one (for the current node) equals k,
        // then this node is the kth ancestor of the target node. Store it in the ancestorData.
        if (leftDistance + 1 == k) {
            *ancestorData = root->data;
        }
        // Return the distance of the target node from the current node in the left subtree.
        return leftDistance + 1;
    } else if (rightDistance != -1 && leftDistance == -1) {
        // If the node is found in the right subtree and its distance from the target node plus one (for the current node) equals k,
        // then this node is the kth ancestor of the target node. Store it in the ancestorData.
        if (rightDistance + 1 == k) {
            *ancestorData = root->data;
        }
        // Return the distance of the target node from the current node in the right subtree.
        return rightDistance + 1;
    }

    // If the target node is not found in the left or right subtree, return -1 to indicate that.
    return -1;
}

// Function to find the kth ancestor of the given node in the binary tree
int kthAncestor(Node* root, int k, int nodeData) {
    // Variable to store the data of the kth ancestor
    int ancestorData = -1;

    // Call the helper function to find the kth ancestor of the target node
    findKthAncestor(root, k, nodeData, &ancestorData);

    // Return the data of the kth ancestor, which will be -1 if the ancestor doesn't exist
    return ancestorData;
}

// Function to find the kth ancestor of the given node in the binary tree
int kthAncestor(Node* root, int k, int nodeData) {
    // Variable to store the data of the kth ancestor
    int ancestorData = -1;

    // Call the helper function to find the kth ancestor of the target node
    findKthAncestor(root, k, nodeData, &ancestorData);

    // Return the data of the kth ancestor, which will be -1 if the ancestor doesn't exist
    return ancestorData;
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
