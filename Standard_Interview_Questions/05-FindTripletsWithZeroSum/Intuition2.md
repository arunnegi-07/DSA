## Intuition

**Two-Pointer Technique:**
The two-pointer technique involves using two pointers, typically referred to as left and right, to narrow down the 
search space and efficiently find the desired solution.

In this approach we will try to reduce the space complexity and reduce it to O(1).

**This approach is simple to understand, so let us see what we are going to do :** 

1. **Sorting for Simplicity :** Sorting the array in ascending order helps simplify the problem. It allows us to consider elements in a systematic manner and reduces the search space. 

2. **Targeting Zero Sum :** To find a triplet with a sum of zero, we need to target combinations of three elements that add up to zero. Sorting the array helps us identify potential elements for the triplet.

3. **Choosing Pointers :** In this solution, we start by fixing the first element of the potential triplet. We then use two pointers, left and right, to point to the second and third elements, respectively. Initially, left points to the next element after the first, and right points to the last element of the array.

4. **Checking the Triplet Sum:** We calculate the sum of the current triplet using arr[first] + arr[left] + arr[right]. 
    
**Based on this sum, we have three possibilities :** 
```
1. If the sum is less than zero, it means the sum needs to be increased. Since the array is sorted, moving the 'left' pointer
to the right will increase the sum.
  
2. If the sum is greater than zero, it means the sum needs to be decreased. Again, due to the sorted array, moving the 
    right pointer to the left will decrease the sum.

3. If the sum is equal to zero, we have found a triplet with a sum of zero, and we return true.
    
Moving the Pointers: Depending on the sum, we manipulate the pointers as follows:
    a. If the sum is less than zero, we increment the left pointer (left++).
    b. If the sum is greater than zero, we decrement the right pointer (right--).
   
We repeat the process until the left pointer is less than the right pointer. This ensures that we explore all possible
combinations of elements.
If we exhaust all possible combinations without finding a triplet with a sum of zero, we return false.
```

By using the two-pointer approach, we effectively narrow down the search space, by taking advantage of sorting the array. This approach optimizes the solution with a time complexity of O(n<sup>2</sup>) by eliminating the need for nested loops, resulting in an efficient solution to find triplets with a sum of zero.

**Note:** Just dry run by taking some sample exmples to better understand this approach completely.