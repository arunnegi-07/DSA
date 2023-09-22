## Problem : Find First and Last Occurences (Medium)
Given a sorted array **arr** containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element **x** in the given array.
**Note:** If the number **x** is not found in the array then return both the indices as **-1**.


**Example 1:**
```
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }

Output:  
2 5

Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
```

**Example 2:**
```
Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }

Output:  
6 6

Explanation: 
First and last occurrence of 7 is at index 6.
```

**Your Task:**
```
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function 
find() that takes array arr, integer n and integer x as parameters and returns the required answer.
```
**Expected Time Complexity:** O(logN)```<br>
**Expected Auxiliary Space:** O(1)```

**Constraints:**
<li>1 ≤ <b>N</b> ≤ 10<sup>6</sup></li>
<li>1 ≤ <b>Narr[i]</b>,<b>x</b> ≤ 10<sup>9</sup></li>