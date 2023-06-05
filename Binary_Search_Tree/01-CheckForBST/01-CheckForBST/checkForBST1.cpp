#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Simpler to understand as compared to Approach 2
// TC : O(N)   SC : O(Height of Tree) 

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
bool validBST(Node *root,int& maxi,int& mini){
    // If the root is NULL, it is a valid BST
    if(!root) return true;
        
    // variables to store all the information about the subTree below
    bool leftFlag = true,rightFlag = true;
    int leftMax = INT_MIN,rightMax = INT_MIN;
    int leftMin = INT_MAX,rightMin = INT_MAX;
        
    // Recursively checking the left and right subtrees
    leftFlag = validBST(root -> left,leftMax,leftMin);
    rightFlag = validBST(root -> right,rightMax,rightMin);
        
    // Minimum and Maximum till a subTree
    maxi = max(root -> data,max(leftMax,rightMax));
    mini = min(root -> data,min(leftMin,rightMin));
        
    // setting flag as false initially before checking if it is really a BST or not
    // This variable stores status of subTree if it's a BST or not
    bool currFlag = false;
        
    // checking current SubTree if it is a BST or not
    if(root -> data > leftMax && root -> data < rightMin && leftFlag && rightFlag) 
        currFlag = true;  // means subTree is a BST
        
    return currFlag;
}
    
//Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) 
{
    // setting min and max intially to INT_MIN and INT_MAX respectively, these are used to check parent
    // is greater than left child and smaller than right child, which is the property of BST
    int maxi = INT_MIN,mini = INT_MAX;
        
    // calling helper function to check if BST or not
    return validBST(root,maxi,mini);
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
