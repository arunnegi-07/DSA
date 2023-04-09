## Problem : Closest 3 Sum (Medium)

Given an array ```A[]``` of ```N``` integers and an integer ```X```. The task is to find the sum of three integers in ```A[]``` such that it is closest to ```X```.


**Example 1:**
```
Input:
N = 4
A[] = {-1 , 2, 1, -4}
X = 1

Output: 2

Explaination: 
Sums of triplets:
(-1) + 2 + 1 = 2
(-1) + 2 + (-4) = -3
2 + 1 + (-4) = -1
2 is closest to 1.
```

**Example 2:**
```
Input:
N = 5
A[] = {1, 2, 3, 4, -5}
X = 10

Output: 9

Explaination: 
Sums of triplets:
1 + 2 + 3 = 6
2 + 3 + 4 = 9
1 + 3 + 4 = 7
...
9 is closest to 10.
```

**Your Task:**
```
You don't need to read input or print anything. Your task is to complete the function closest3Sum() which takes the array Arr[] and 
its size N and X as input parameters and returns the sum which is closest to X.
```

**NOTE:** If there exists more than one answer then return the maximum sum.

**Expected Time Complexity:** ```O(N^2)```<br>
**Expected Auxiliary Space:** ```O(1)```

**Constraints:**
<ul>
<li><code>3 ≤ N ≤ 10<sup>3</sup></code></li>
<li><code>-10<sup>3</sup> ≤ Arr[i] ≤ 10<sup>3</sup></code></li>
<li><code>-10<sup>4</sup> ≤ X ≤ 10<sup>4</sup></code></li>
</ul>