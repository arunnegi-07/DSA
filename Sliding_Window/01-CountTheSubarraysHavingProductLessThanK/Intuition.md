## Intuition : 

**Why Sliding Window for this problem :**
The sliding window technique is commonly used for solving problems that involve finding subarrays or substrings that satisfy certain conditions. It optimizes the solution by maintaining a window of elements within the array and adjusting the window based on the problem requirements. The window starts with a minimal size and expands or shrinks as needed, eliminating unnecessary calculations and improving efficiency.

**Let's take an example to illustrate how the sliding window technique is used here :**
```
Consider the input : 
        a = [1, 2, 3, 4]
        k = 10

We'll go through the steps of the sliding window technique using this example:

Initialize two pointers, i and j, to track the 'start' and 'end' of the subarray. 
Also, initialize 'product' as 1 (the initial product of an empty subarray), and 
'count' as 0 (the count of subarrays).

For now,
                i = 0, j = 0, product = 1, count = 0
                Begin iterating the end pointer 'j' over the array.
```

**Step 1:**
``` 
Multiply the product by the element at index 'j' (1 in this case).

product = 1 * 1 = 1
```
**Step 2:**
```
Check if the product is greater than or equal to 'k'. If it is, move the start pointer 'i' towards the 
right until the product becomes less than 'k'.

Since the product (1) is less than 'k', we proceed to the next step.
```
**Step 3:**
```
Check if the product is less than 'k'. If it is, update 'count' by adding the length of the current 
subarray (j - i + 1) to it.

Since the product (1) is less than 'k', we add the length of the subarray [1] to count.

count = coung + (j - i + 1) = 0 + (0 - 0 + 1) = 1
```
**Step 4:**
```
Move the end pointer j towards the right to expand the window.

j = j + 1 = 0 + 1 = 1
```

**Repeat steps 2-4** for the next elements in the array.
```
    Step 2: Multiply the product by the element at index end (2 in this case).

                product = 1 * 2 = 2

    Step 3: Check if the product is less than 'k'. Since 2 is less than 10, we add the length of the
                subarray [2] to count.

                 count = count + (end - start + 1) = 1 + (1 - 0 + 1) = 3

    Step 4: Move the end pointer end towards the right to expand the window.

                end = end + 1 = 1 + 1 = 2

    Again repeat, 
    Step 2: Multiply the product by the element at index end (3 in this case).
                
                product = 2 * 3 = 6

    Step 3: Check if the product is less than 'k'. Since 6 is less than 10, we add the length of the 
                subarray [2, 3] to count.

                count = count + (end - start + 1) = 3 + (2 - 0 + 1) = 6

    Step 4: Move the end pointer end towards the right to expand the window.

                end = end + 1 = 2 + 1 = 3

    Again repeat, 
    Step 2: Multiply the product by the element at index end (4 in this case).

                product = 6 * 4 = 24

    Step 3: Check if the product is less than k. Since 24 is greater than 10, we need to move the 
                start pointer start towards the right until the product becomes less than k.

    Move start to the right and divide the product by the element at index start.

                product = product / a[start] = 24 / 1 = 24

    Move start to the right again and divide the product by the element at index start.

                product = product / a[start] = 24 / 2 = 12

    Step 3: Check if the product is less than 'k'. Since 12 is less than 10, we add the length of the
                subarray [4] to count.

                count = count + (end - start + 1) = 6 + (3 - 2 + 1) = 7

    Step 4: Move the end pointer end towards the right to expand the window.

                end = end + 1 = 3 + 1 = 4
    
    The end pointer end has reached the end of the array, so we stop the iteration.
```

**Now, as 'end' pointer reached the end so we will stop :**
```
Now, the final result is stored in count, which is the count of subarrays with a product less than k.

count = 7

Therefore, 
    the number of contiguous subarrays in the given array [1, 2, 3, 4] having a product less than 10 is 7.
```

**Note:**
The sliding window technique optimizes the solution by maintaining a window of elements and adjusting the window based on the problem requirements. In this example, the window expands to the right when the product is less than 'k' and shrinks from the left when the product exceeds 'k'. This way, we only consider the necessary elements and avoid redundant calculations, resulting in an efficient solution with a time complexity of **O(n)**.