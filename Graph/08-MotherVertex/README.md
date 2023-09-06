## Problem : Mother Vertex (Easy)
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

**Example 1:**

<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701116/Web/Other/a5cc2f40-e569-4761-b6df-16b72658a270_1685086764.png">

```
Output: 
0

Explanation: 
According to the given edges, all 
nodes can be reached from nodes from 0, 1 and 2. 
But, since 0 is minimum among 0,1 and 2, so 0 
is the output.
```

**Example 2:**

<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701116/Web/Other/5e3e183b-258d-4f95-9c5d-83eb5f5549ef_1685086764.png">

```
Output: 
-1

Explanation: 
According to the given edges, 
no vertices are there from where we can 
reach all vertices. So, output is -1.
```

**Your Task:**
```
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices 
and adjacency list as input parameter and returns the vertices from through which we can traverse all other vertices of the graph. If there is 
more than one possible nodes then return the node with minimum value. If not possible returns -1.
```

**Expected Time Complexity:** ```O(V + E)```<br>
**Expected Space Complexity:** ```O(V)```

**Constraints:**
<li>1 ≤ <b>V</b> ≤ 500</li>


