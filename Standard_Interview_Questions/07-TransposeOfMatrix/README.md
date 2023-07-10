## Problem : Transpose Of Matrix (Easy)
Write a program to find the transpose of a square matrix of size **N*N**. Transpose of a matrix is obtained by changing rows to columns and columns to rows.

**Example 1:**
```
Input:
N = 4
mat[][] = {{1, 1, 1, 1},
                {2, 2, 2, 2}
                {3, 3, 3, 3}
                {4, 4, 4, 4}}

Output: 
{{1, 2, 3, 4},  
 {1, 2, 3, 4}  
 {1, 2, 3, 4}
 {1, 2, 3, 4}} 
```

**Example 2:**
```
Input:
N = 2
mat[][] = {{1, 2},
               {-9, -2}}

Output:
{{1, -9}, 
{2, -2}}
```

**Your Task:**
```
You dont need to read input or print anything. Complete the function transpose() which takes matrix[][]
and N as input parameter and finds the transpose of the input matrix. You need to do this in-place. That 
is you need to update the original matrix with the transpose. 
```

**Expected Time Complexity:** ```O(N * N)```<br>
**Expected Auxiliary Space:** ```O(1)```

**Constraints:**
<li>1 <= <b>N</b> <= 10<sup>3</sup></li>
<li>-10<sup>9</sup> <= <b>mat[i][j]</b> <= 10<sup>9</sup></li>