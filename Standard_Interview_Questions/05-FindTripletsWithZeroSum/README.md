## Problem : Find Triplets with Zero Sum (Easy)
Given an array **arr[]** of n integers. Check whether it contains a triplet that sums up to zero. 

**Note:** Return **1**, if there is at least one triplet following the condition else return **0**.

**Example 1:**
```
Input:
n = 5, arr[] = {0, -1, 2, -3, 1}

Output: 1

Explanation: 
0, -1 and 1 forms a triplet with sum equal to 0.
```

**Example 2:**
```
Input:
n = 3, arr[] = {1, 2, 3}

Output: 0

Explanation: 
No triplet with zero sum exists. 
```

**Your Task:**
```
You don't need to read input or print anything. Your task is to complete the boolean function findTriplets()
which takes the array arr[] and the size of the array (n) as inputs and print 1 if the function returns true else
print 0 if the function returns false. 
```

**Expected Time Complexity:** ```O(n²)```<br>
**Expected Auxiliary Space:** ```O(1)```

**Constrains:**
<li>1 <= <b>n</b> <= 10<sup>4</sup></li>
<li>-10<sup>6</sup> <= <b>A<sub>i</sub></b> <= 10<sup>6</sup></li>
