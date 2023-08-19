## Intuition :
This Approach is very simple and also very optimal to solve this problem.
1. We are using '2' pointers 'left' and 'right' initially set to '0', and we keep on
    doing 'sum' using 'right' pointers.

2. if 'sum' become greater than given sum, we increment 'left' inorder to shrink
    our subArray and subtract the value from our 'sum' we are calculating as we have
    removed elements from the subArray,
    and if 'sum' is smaller than given 'sum' we just increment our 'right'
    pointer and add next element to the sum.

3. And, if sum is equal to the given sum, then we simply return the positions.

    We keep on repeating step 1 and 2 until we got our sum (or) left <= N , and if didn't found any subArray we return '-1'.