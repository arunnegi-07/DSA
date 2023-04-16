## Problem : Unequal Arrays (Medium)

You are given two arrays ```A``` and ```B``` each of length ```N```.<br><br>
You can perform the following operation on array ```A``` zero or more times. 
<ul>
<li><code>Select any two indices <b>i<b> and <b>j<b>, <b>1 <= i<b> , <b>j <= N<b> and <b>i != j<b></code></li>
<li><code>Set <b>A[i] = A[i] + 2<b> and <b>A[j] = A[j]-2<b></code></li>
</ul>
<br>

Find the **minimum** number of operations required to make A and B **equal**.

**Note:**
<ul>
<li><code>Two arrays are said to be equal if the frequency of each element is equal in both of them.</code></li>
<li><code>Arrays may contain duplicate elements.</code></li>
</ul>

**Example 1:**
```
Input:
N = 3
A[] = {2, 5, 6}
B[] = {1, 2, 10}

Output: 2

Explanation: 
Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
Select i = 3, j = 2, A[3] = 10 - 2 = 8 and A[2] = 3 - 2 = 1
Now A = {2, 1, 10} and B = {1, 2, 10}
```

**Example 2:**
```
Input:
N = 2
A[] = {3, 3}
B[] = {9, 8}

Output: -1

Explanation: 
It can be shown that A cannot be made equal to B.
```

**Your Task:**
``` 
You don't need to read input or print anything. Your task is to complete the function solve() which takes the 2 arrays A[], B[]
and their size N as input parameters and returns the minimum number of moves to make A and B equal if possible else return -1.
```

**Expected Time Complexity:** ```O(NlogN)```<br>
**Expected Auxiliary Space:** ```O(N)```

**Constraints:**
<ul>
<li><code>1 <= N <= 10<sup>5</sup></code></li>
<li><code>-10<sup>9</sup> <= A[i] <= 10<sup>9</sup></code></li>
<li><code>-10<sup>9</sup> <= B[i] <= 10<sup>9</sup></code></li>
</ul>