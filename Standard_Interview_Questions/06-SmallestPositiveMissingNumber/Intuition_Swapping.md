## Intuition :

**Note :**Before coming to this approach please clear the previous approach as the concept behind this approach
is totally similar to that one.

**Here's a step-by-step intuition of the in-place swapping approach:**
1. Iterate through the array and for each element **arr[i]**, swap it with **arr[arr[i] - 1]** if **arr[i]** is positive and less
    than or equal to **N**. This swapping step aims to place each positive number at its correct index, if possible.

2. Repeat this swapping process until all positive numbers in the array are at their correct positions, i.e. **arr[i]** equals **i+1** 
    for every positive number **arr[i]**.

3. After the swapping process is complete, iterate through the modified array again and return the index of the first element 
   that does not satisfy **arr[i]** = **i+1**. This index represents the smallest positive missing number.

The key intuition of the in-place swapping approach is to use the array indices to rearrange the elements and place each positive number at its corresponding index. By doing so, any missing positive number will cause a mismatch between the element and its index, which allows us to identify the smallest positive missing number.

**Note :** Just dry run this appraoch using all the sample examples given in the previous approach and it will become clear as this appraoch
is conceptually very similar to that one.
 
