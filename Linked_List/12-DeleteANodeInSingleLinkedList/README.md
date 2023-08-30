## Problem : Delete a Node in Single Linked List (Easy)
Given a singly linked list and an integer **x**.Delete **x<sup>th</sup>** node from the singly linked list.

**Example 1:**
```
Input: 1 -> 3 -> 4 
       x = 3

Output: 1 -> 3

Explanation:
After deleting the node at 3rd position (1-base indexing) the linked list is as 1 -> 3. 
```

**Example 2:**
```
Input: 1 -> 5 -> 2 -> 9 
x = 2

Output: 1 -> 2 -> 9

Explanation: After deleting the node at 2nd position (1-based indexing), the linked list is as 1 -> 2 -> 9.
```

**Your task:** 
```
Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x.
The function returns the head of the modified linked list.
```
**Expected Time Complexity:** ```O(N)```<br>
**Expected Auxiliary Space:** ```O(1)```

**Constraints:**
<li>2 <= <b>N</b> <= 10<sup>5</sup></li>
<li>1 <= <b>x</b> <= N</li>


