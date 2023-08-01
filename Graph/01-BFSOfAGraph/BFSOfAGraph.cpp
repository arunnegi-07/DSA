// TC :  O(V+E  SC : O(V)  where, V : no. of vertices  E : no. of edges
 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    int vis[V] = {0}; // Create an array to track visited vertices, initialized with 0 (not visited)
    queue<int> q; // Create a queue to perform BFS traversal
    q.push(0); // Start the BFS traversal from vertex 0 (you can start from any other vertex as well)
    vis[0] = 1; // Mark vertex 0 as visited
    vector<int> res; // Vector to store the BFS traversal result

    while (!q.empty()) { // Continue the BFS traversal until the queue is empty
        int x = q.front(); // Get the front vertex from the queue
        q.pop(); // Remove the front vertex from the queue
        res.push_back(x); // Add the current vertex to the BFS traversal result

        for (auto i : adj[x]) { // Iterate through all the adjacent vertices of the current vertex
            if (vis[i] != 1) { // If the adjacent vertex is not visited
                q.push(i); // Push it into the queue for further exploration
                vis[i] = 1; // Mark the adjacent vertex as visited
            }
        }
    }
    return res; // Return the BFS traversal result
}

int main() {
    // Sample input 1
    vector<vector<int>> adj1 = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };

    vector<int> result1 = bfs(adj1);
    cout << "BFS traversal result for Sample Input 1: ";
    for (int vertex : result1) {
        cout << vertex << " ";
    }
    cout << endl;

    // Sample input 2
    vector<vector<int>> adj2 = {
        {1, 2, 3},
        {0, 3},
        {0, 3},
        {0, 1, 2}
    };

    vector<int> result2 = bfs(adj2);
    cout << "BFS traversal result for Sample Input 2: ";
    for (int vertex : result2) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
