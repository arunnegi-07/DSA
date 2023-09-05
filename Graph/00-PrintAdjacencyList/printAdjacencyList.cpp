// TC : O(V+E)  SC : O(V+E)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(V);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // Adding edges for both directions since it's an undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    vector<vector<int>> adjList = printGraph(V, edges);

    // Printing the adjacency list
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " is connected to: ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
