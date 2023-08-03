// Using Depth First Search (DFS)
// TC : O(V*V)  SC : O(V)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<int> adjList[], vector<int> &vis) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adjList[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    // Converting the adjacency matrix to an adjacency list for efficient traversal.
    vector<int> adjList[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // If there is an edge between nodes i and j and they are not the same node (i!=j),
            // add them to each other's adjacency list.
            if (adj[i][j] && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    // Create a vector to mark the visited nodes. Initialize all nodes as unvisited (0).
    vector<int> vis(V, 0);

    // Initialize a variable to keep track of the number of provinces found in the graph.
    int provinces = 0;

    // Iterate through all the nodes (vertices) of the graph.
    for (int i = 0; i < V; i++) {
        // If the current node has not been visited yet, start BFS from it to explore its connected component.
        if (!vis[i]) {
            bfs(i, adjList, vis); // Call BFS on the current node and its connected component.
            provinces++; // Increment the number of provinces, as a new connected component is found.
        }
    }

    // Return the total number of provinces in the graph.
    return provinces;
}

int main() {
    // Sample Input 1:
    vector<vector<int>> adjMatrix1 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    int V1 = 3;

    int provinces1 = numProvinces(adjMatrix1, V1);
    cout << "Number of provinces in Sample Input 1: " << provinces1 << endl;
    // Expected Output: 2

    // Sample Input 2:
    vector<vector<int>> adjMatrix2 = {
        {1, 1},
        {1, 1}
    };
    int V2 = 2;

    int provinces2 = numProvinces(adjMatrix2, V2);
    cout << "Number of provinces in Sample Input 2: " << provinces2 << endl;
    // Expected Output: 1

    return 0;
}
