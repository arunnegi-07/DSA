## Problem : Remove Duplicates from a Sorted Linked List (Easy)
Given a singly linked list consisting of **N** nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
**Note:** Try not to use extra space. The nodes are arranged in a sorted way.

**Example 1:**
```
Input:
LinkedList: 2->2->4->5

Output: 2 4 5

Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time. So we need to remove it once.
```

**Example 2:8**
```
Input:
LinkedList: 2->2->2->2->2

Output: 2

Explanation: In the given linked list 
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times. So we need to remove
any four 2.
```
**Your Task:**
```
The task is to complete the function removeDuplicates() which takes the head of input linked list as input. The function should remove the duplicates from linked list and return the head of the linkedlist.
```

**Expected Time Complexity :** ```O(N)```<br>
**Expected Auxilliary Space :** ```O(1)```

**Constraints:**
<li>1 <= <b>Number of nodes</b> <= 10<sup>5</sup></li>


