// TC : O(N)  SC : O(N)

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node* root) {
    vector<int> result;

    if (!root)
        return result;

    deque<Node*> queue;
    queue.push_back(root);
    int level = 0;

    while (!queue.empty()) {
        int level_length = queue.size();
        vector<int> level_values;

        for (int i = 0; i < level_length; ++i) {
            if (level % 2 == 0) { // Even level, print from right to left
                Node* node = queue.back();  // Get the last node in the deque
                queue.pop_back();           // Remove the last node from the deque
                level_values.push_back(node->data);  // Add the node's value to the level_values vector
                if (node->right)
                    queue.push_front(node->right);  // Add the right child to the front of the deque
                if (node->left)
                    queue.push_front(node->left);   // Add the left child to the front of the deque
            } else { // Odd level, print from left to right
                Node* node = queue.front();   // Get the first node in the deque
                queue.pop_front();            // Remove the first node from the deque
                level_values.push_back(node->data);  // Add the node's value to the level_values vector
                if (node->left)
                    queue.push_back(node->left);   // Add the left child to the end of the deque
                if (node->right)
                    queue.push_back(node->right);  // Add the right child to the end of the deque
            }
        }

        // Copying values of 'level_values' to the end of 'result' vector
        result.insert(result.end(), level_values.begin(), level_values.end());

        ++level; // Move to the next level
    }

    return result;
}

int main() {
    // Sample Input:
    //      1
    //     / \
    //    3   2
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    // Calling the findSpiral function to get the spiral order traversal
    vector<int> spiralTraversal = findSpiral(root);

    // Printing the result
    cout << "Spiral Order Traversal: ";
    for (int val : spiralTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
