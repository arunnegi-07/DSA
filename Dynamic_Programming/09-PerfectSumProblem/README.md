## Problem : Perfect Sum Problem (Medium)
Given an array **arr[]** of non-negative integers and an integer **sum**, the task is to count all subsets of the given array with a sum equal to a given **sum**.

**Note:** Answer can be very large, so, output answer modulo 10<sup>9</sup>+7

**Example 1:**
```
Input: 
N = 6, arr[] = {2, 3, 5, 6, 8, 10}
sum = 10

Output: 3

Explanation: {2, 3, 5}, {2, 8}, {10} are possible subsets.
```

**Example 2:**
```
Input: 
N = 5, arr[] = {1, 2, 3, 4, 5}
sum = 10

Output: 3

Explanation: {1, 2, 3, 4}, {1, 4, 5}, {2, 3, 5} are possible subsets.
```

**Your Task:**
```
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value.
```

**Expected Time Complexity:** ```O(N*sum)```<br>
**Expected Auxiliary Space:** ```O(N*sum)```

**Constraints:**
<li>1 ≤ <b>N*sum</b> ≤ 10<sup>6</sup></li>
<li>0 ≤ <b>arr[i]</b> ≤ 10<sup>6</sup></li>
