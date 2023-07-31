## Problem : BFS of Graph (Easy)
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.<br>
**Note:** One can move from node **u** to node **v** only if there's an edge from **u** to **v**. Find the BFS traversal of the graph starting from the **0th** vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


**Example 1:**
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web//e0eb5630-5d6c-493a-9b1e-d16d40f10b01_1685086421.png">

```
Output: 0 1 2 3 4

Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2 then 3.
After this 2 to 4, thus bfs will be0 1 2 3 4.
```

**Example 2:**
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web/Other/001e9e35-da68-4024-b1d3-e34944188a1e_1685086422.png">

```
Output: 0 1 2

Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2, thus bfs will be 0 1 2. 
```

**Your task:**
```
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() 
which takes the integer V denoting the number of vertices and adjacency list as input parameters 
and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.
```

**Expected Time Complexity:** ```O(V + E)```<br>
**Expected Auxiliary Space:** ```O(V)```

**Constraints:**
<li>1 ≤ <b>V</b>, <b>E</b> ≤ 10<sup>4</sup></li>
