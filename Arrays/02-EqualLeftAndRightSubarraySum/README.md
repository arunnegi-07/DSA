## Problem : Equal Left And Right Subarray Sum (Easy)

Given an ```array A``` of ```n``` positive numbers. The task is to find the first index in the array such that the <b>sum of elements before it is equal to the sum of elements after it.</b>

<strong>Note:</strong>  Array is 1-based indexed.

<strong>Example 1:</strong>
```
Input: 
n = 5 
A[] = {1,3,5,2,2} 

Output: 3 

Explanation: For second test case 
at position 3 elements before it 
(1+3) = elements after it (2+2). 
```
<strong>Example 2:</strong>
```
Input:
n = 1
A[] = {1}

Output: 1

Explanation:
Since its the only element hence
it is the only point.
```
<strong>Your Task:</strong>
```
The task is to complete the function equalSum() which takes the array and n as input parameters and returns the point.
Return -1 if no such point exists.
```

<strong>Expected Time Complexily:</strong> ```O(N)```<br>
<strong>Expected Space Complexily:</strong> ```O(1)```

<strong>Constraints:</strong>
<ul>
<li><code>1 <= n <= 10<sup>6</sup></code></li>
<li><code>1 <= A[i] <= 10<sup>6</sup></code></li>
</ul>