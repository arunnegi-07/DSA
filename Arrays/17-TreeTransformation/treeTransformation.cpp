// TC : O(N)  SC : O(N)

// This Problem is all about counting the internal nodes and that will be our answer.
// If you dry run 2-3 examples by yourself we will get that thing.
// and after that just find no. of internal nodes with given array. (Note: Input is not in form of a tree)

#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> p){
    
    // Array to store no. of connections of each node
    // vector<int> connections(N,0);
    int connections[N] = {0};

    // Step 1 :
    // finding connections of every node
    for (int i = 0; i < N; i++)
    {
        // case for root node
        if (p[i] == -1)
        {
            connections[i] = 0;
            continue;
        }

        // other then root nodes

        //   0  1  2  3  4  --> indices
        // {-1, 0, 0, 1, 1}

        /* Ex:  0 --> i here is '2' (acc. to above given array)
                 \
                  2   */

        // updating connection array according to above example
        connections[i]++;    //  connection[2]++ , means node 2 got a connection
        connections[p[i]]++; //  connection[p[2]]++ = connection[0]++ , means node 0 has connection
                             // from above diagram also it is clear 0 and 2 has connection with each other
        // we will repeat same step to find connection for all the nodes.
    }

    // for(auto i : connections){
    //   cout << i << " ";
    // }

    // Step 2:
    // Finding count of all the leaf nodes

    int leaf_count = 0;

    for (int i = 0; i < N; i++)
    {
        // only those nodes are leaf node which has only one connection
        if (connections[i] == 1)
        {
            leaf_count++;
        }
    }

    // Step 3:
    // returning no. of internal nodes as the answer

    if (N - leaf_count - 1 < 0)
        return 0; // base case if either tree is empty or tree is already a star tree.

    return N - leaf_count - 1;
}

int main() {
    // Sample inputs
    int N = 5;
    vector<int> p = {-1, 0, 0, 1, 1};
    
    int result = solve(N, p);
    
    cout << "Number of internal nodes: " << result << endl;
    
    return 0;
}