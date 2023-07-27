## Problem : Right View of a Binary Tree (Easy)
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is **1 3 7 8**.
```
            1
         /     \
       2        3
     /   \    /   \
    4     5  6     7
     \
      8
```
   
**Example 1:**
```
Input:
       1
    /    \
   3      2

Output: 1 2
```

**Example 2:**
```
Input:
     10
    /   \
  20     30
 /   \
40  60 

Output: 10 30 60
```

**Your Task:**
```
Just complete the function rightView() that takes node as parameter and returns the right view as a list. 
```

**Expected Time Complexity:** ```O(N)```<br>
**Expected Auxiliary Space:** ```O(Height of the Tree)```

**Constraints:**
<li>1 ≤ <b>Number of nodes</b> ≤ 10<sup>5</sup></li>
<li>0 ≤ <b>Data of a node</b> ≤ 10<sup>5</sup></li>
