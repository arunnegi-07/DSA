## Problem : Level Order Traversal in Spiral Form (Easy)
Given a binary tree and the task is to find the spiral order traversal of the tree.
<br>

**Spiral order Traversal mean:** Starting from **level 0** for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 

For below tree, function should return **1**, **2**, **3**, **4**, **5**, **6**, **7**.

<p align="center">
<img src="https://contribute.geeksforgeeks.org/wp-content/uploads/level.jpg">
</p>

**Example 1:**
```
Input:
      1
    /   \
   3     2

Output:
1 3 2
```


**Example 2:**
```
Input:
           10
         /     \
        20     30
      /    \
    40     60

Output: 
10 20 30 60 40 
```

**Your Task:**
```
The task is to complete the function findSpiral() which takes root node as input parameter and
returns the elements in spiral form of level order traversal as a list. The newline is automatically 
appended by the driver code.
```

**Expected Time Complexity:** ```O(N)```<br>
**Expected Auxiliary Space:** ```O(N)```

**Constraints:**
<li>1 <= <b>Number of nodes</b> <= 10<sup>5</sup></li>
<li>0 <= <b>Data of a node</b> <= 10<sup>5</sup></li>


