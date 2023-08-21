## Problem : Upper Bound (Easy)
You are given  an array **arr** sorted in non-decreasing order and a number **x**.

You must return the index of upper bound of **x**.

**Note :**
1. For a sorted array **arr**, **upper_bound** of a number **x** is defined as the smallest index **idx** such that the value **arr[idx]** is **not less than** and
**equal** to **x**. 
```
        not less than and equal to 'x' , means --> greater than to 'x'

                                    i.e arr[idx] >= x

            then 'idx' is the upper_bound of 'x'
        
        Overall : upper_bound of 'x' is the value which is smallest among all the values which are greater than 'x'
                       but not equal to 'x'. 
```

**Important:** So, upper_bound is similar to lower_bound except it does not consider 'equal to' value.


**Example 1 :**
```         
                             0  1  2  3  4  5  --> indices            
                    arr = 1  2  2  3  3  5
                    x = 2
        
        for x = 2, value which is smallest as well as greater than  'x'
                        is '3' which is at 'idx' = '3'

            therefore, idx = '3' is the upper_bound of 'x'.
    
    Note : If more than one elements are same and possible to be upper_bound then
                choose one with lower index.
```

**Example 2 :**
```
                         0  1  2  3   4    5  --> indices            
                arr = 4  6  7  9  10  20
                x = 8
    
    for x = 8, value which is smallest as well as greater than 'x'
                    is '9' which is at 'idx' = '3'

        therefore, idx = '3' is the upper_bound of 'x'.
```

2. If all numbers are smaller than **x**, then **n** should be the **upper_bound** of **x**, where **n** is the size
    of array.

3. Consider **0-based indexing**.

**Expected Time Complexity:** ```O(LogN)```<br>
**Expected Auxiliary Space:** ```O(1)``` 

**Constraints:**
<li>1 <= <b>n</b> <= 10<sup>5</sup></li>
<li>0 <= <b>arr[i]</b> <= 10<sup>5</sup></li>
<li>1 <= <b>x</b> <= 10<sup>5</sup></li>