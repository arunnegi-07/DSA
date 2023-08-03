// Using Concept of Dijkstra's Algorithm
// TC : O(N+M), where N is the number of nodes and M is edges   SC : O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<int> dist(N, -1); // Initialize the distance array with -1 (representing not reachable)

    // Create a priority queue to keep track of vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap

    pq.push({0, 0}); // Start from the source vertex 0 with distance 0

    while (!pq.empty()) {
        int distance = pq.top().first; // Get the distance of the current vertex from the source
        int u = pq.top().second; // Get the current vertex
        pq.pop(); // Remove the current vertex from the priority queue

        // If we have already visited the vertex, continue to the next one
        if (dist[u] != -1) {
            continue;
        }

        dist[u] = distance; // Mark the current vertex as visited with the given distance

        for (const vector<int>& edge : edges) {
            if (edge[0] == u) { // Check if there is an edge from the current vertex
                int v = edge[1]; // Get the destination vertex of the edge
                int weight = edge[2]; // Get the weight of the edge

                // Calculate the new distance to reach the destination vertex through the current vertex
                int new_distance = distance + weight;

                pq.push({new_distance, v}); // Push the destination vertex and its updated distance to the priority queue
            }
        }
    }

    return dist;
}

int main() {
    // Example 1
    int N1 = 4;
    int M1 = 2;
    vector<vector<int>> edges1 = {{0, 1, 2}, {0, 2, 1}};
    vector<int> result1 = shortestPath(N1, M1, edges1);
    for (int dist : result1) {
        cout << dist << " ";
    }
    cout << endl;

    // Example 2
    int N2 = 6;
    int M2 = 7;
    vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> result2 = shortestPath(N2, M2, edges2);
    for (int dist : result2) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
