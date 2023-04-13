## Problem : Remove Cycle From a Linked List (Medium)

Given a linked list of ```N``` nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position ``X`` (**1-based index**).<br>
If the link list does not have any loop, ```X=0```.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

**Example 1:**
```
Input:
N = 3
value[] = {1,3,4}
X = 2

Output: 1

Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
```

**Example 2:**
```
Input:
N = 4
value[] = {1,8,3,4}
X = 0

Output: 1

Explanation: The Linked list does not 
contains any loop. 
```

**Example 3:**
```
Input:
N = 4
value[] = {1,2,3,4}
X = 1

Output: 1

Explanation: The link list looks like 
1 -> 2 -> 3 -> 4
     |_________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. 
```

**Your Task:**
```
You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes 
the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without 
disconnecting any nodes from the list.
```
**Note:** The generated output will be 1 if your submitted code is correct.<br><br>

**Expected Time complexity:** ```O(N)```<br>
**Expected Auxiliary space:** ```O(1)```

**Constraints:**
<ul>
<li><code>1 ≤ N ≤ 10<sup>4</sup></code></li>
</ul>
