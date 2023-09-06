// Naive Approach --> Taking each vertex and checking if using it we can reach all by going in-depth using DFS
// TC : O(V*V)  SC : O(V)
// This approach will give TLE for large inputs.

#include <bits/stdc++.h>
using namespace std;

// Depth-First Search (DFS) function to traverse the graph starting from vertex 'v'.
void dfs(int v, vector<int> adj[], vector<bool> &vis) {
    vis[v] = true; // Mark the current vertex as visited.

    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u, adj, vis); // Recursively visit unvisited neighbors.
        }
    }
}

// Function to find a Mother Vertex in the Graph.
int findMotherVertex(int V, vector<int> adj[]) {
    vector<bool> vis(V, false); // Create a boolean array to track visited vertices.

    for (int v = 0; v < V; v++) {
        dfs(v, adj, vis); // Start DFS from vertex 'v'.

        // Checking if all vertices are visited after the DFS traversal.
        int count = 0;
        for (int it : vis) {
            if (it == false) {
                count++;
            }
        }

        if (count == 0) {
            return v; // If all vertices are visited, 'v' is a potential mother vertex.
        }

        // Re-initialize the visited array for the next DFS traversal.
        fill(vis.begin(), vis.end(), false);
    }

    return -1; // If no mother vertex is found, return -1.
}

int main() {
    int V1 = 5; // Number of vertices in the first graph.
    vector<int> adj1[V1];
    
    // Adding edges to the first graph.
    adj1[0].push_back(2);
    adj1[0].push_back(3);
    adj1[1].push_back(0);
    adj1[2].push_back(1);
    adj1[3].push_back(4);

    int mother1 = findMotherVertex(V1, adj1);

    if (mother1 != -1) {
        cout << "A mother vertex in the first graph is: " << mother1 << endl;
    } else {
        cout << "No mother vertex found in the first graph." << endl;
    }

    int V2 = 4; // Number of vertices in the second graph.
    vector<int> adj2[V2];

    // Adding edges to the second graph.
    adj2[0].push_back(1);
    adj2[0].push_back(2);
    adj2[1].push_back(3);

    int mother2 = findMotherVertex(V2, adj2);

    if (mother2 != -1) {
        cout << "A mother vertex in the second graph is: " << mother2 << endl;
    } else {
        cout << "No mother vertex found in the second graph." << endl;
    }

    return 0;
}
