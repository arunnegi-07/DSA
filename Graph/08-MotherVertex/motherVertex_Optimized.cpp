// Optimized Approach --> Using Kosaraju's Algorithm
// TC : O(V+E)  SC : O(V)


#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS for Kosaraju's algorithm
void dfs(int v, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u, adj, vis, st);
        }
    }
    st.push(v);
}

// Function to find a Mother Vertex in the Graph.
int findMotherVertex(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    stack<int> st;

    // Step 1: Perform DFS and fill the stack with vertices
    for (int v = 0; v < V; v++) {
        if (!vis[v]) {
            dfs(v, adj, vis, st);
        }
    }

    // Step 2: Reset visited array
    fill(vis.begin(), vis.end(), false);

    // Step 3: Get the top vertex from the stack
    int potentialMother = st.top();
    st.pop();

    // Step 4: Perform DFS from the potential mother vertex
    dfs(potentialMother, adj, vis, st);

    // Step 5: Check if the potential mother can reach all other vertices
    for (bool it : vis) {
        if (!it) {
            return -1; // The potential mother cannot reach all vertices
        }
    }

    return potentialMother;
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
