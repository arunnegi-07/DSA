## Problem : Binary Search (Basic)
Given a sorted array of size **N** and an integer **K**, find the position(**0-based indexing**) at which **K** is present in the array using binary search.

**Example 1:**
```
Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4

Output: 3

Explanation: 4 appears at index 3.
```

**Example 2:**
```
Input:
N = 5
arr[] = {11 22 33 44 55} 
K = 445

Output: -1

Explanation: 445 is not present.
```

**Your Task:**
```
You dont need to read input or print anything. Complete the function binarysearch() which 
takes arr[], N and K as input parameters and returns the index of K in the array. If K is not 
present in the array, return -1.
```

**Expected Time Complexity:** ```O(LogN)```<br>
**Expected Auxiliary Space:** ```O(LogN)``` if solving recursively and O(1) otherwise.

**Constraints:**
<li>1 <= <b>N</b> <= 10<sup>5</sup></li>
<li>1 <= <b>arr[i]</b> <= 10<sup>6</sup></li>
<li>1 <= <b>K</b> <= 10<sup>6</sup></li>