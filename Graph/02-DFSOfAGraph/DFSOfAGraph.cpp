// TC : O(V+E)  SC : O(V)

#include <iostream>
#include <vector>
using namespace std;

// Depth-First Search (DFS) Traversal Recursive Function
void dfsTraversal(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs) {
    // Mark the current node as visited.
    vis[node]++;

    // Add the current node to the DFS traversal vector.
    dfs.push_back(node);

    // Explore all adjacent nodes of the current node.
    for (int it : adj[node]) {
        // If the adjacent node is not visited, perform DFS on it.
        if (!vis[it]) {
            dfsTraversal(it, adj, vis, dfs);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0); // Array to keep track of visited nodes.
    vector<int> dfs; // Vector to store the DFS traversal.

    // Start DFS traversal from the first node (node 0).
    dfsTraversal(0, adj, vis, dfs);

    return dfs;
}

int main() {
    // Sample Input 1
    int V1 = 5; // Number of nodes in the graph
    vector<int> adj1[V1]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj1[0].push_back(1);
    adj1[0].push_back(2);
    adj1[1].push_back(3);
    adj1[1].push_back(4);

    cout << "DFS Traversal Sample 1: ";
    vector<int> result1 = dfsOfGraph(V1, adj1);
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    // Sample Input 2
    int V2 = 4; // Number of nodes in the graph
    vector<int> adj2[V2]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj2[0].push_back(1);
    adj2[0].push_back(2);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(3);

    cout << "DFS Traversal Sample 2: ";
    vector<int> result2 = dfsOfGraph(V2, adj2);
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
