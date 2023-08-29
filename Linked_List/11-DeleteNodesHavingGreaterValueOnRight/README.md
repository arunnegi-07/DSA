## Problem : Delete Nodes having Greater values on Right (Medium)
Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)

 
**Example 1:**
```
Input:
LinkedList = 12->15->10->11->5->6->2->3

Output: 15 11 6 3

Explanation: 
Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting
them, the linked list would like be 15, 11, 6, 3.
```

**Example 2:**
```
Input:
LinkedList = 10->20->30->40->50->60

Output: 60

Explanation: All the nodes except the last node has a greater value node on its right,
so all the nodes except the last node must be removed.
```

**Your Task:**
``` 
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. 
The printing is done by the driver code.
```

**Expected Time Complexity:** ```O(N)```<br>
**Expected Auxiliary Space:** ```O(1)```

**Constraints:**
<li>1 ≤ <b>size of linked list</b> ≤ 10<sup>5</sup></li>
<li>1 ≤ <b>element of linked list</b> ≤ 10<sup>5</sup></li>

**Note:** Try to solve the problem without using any extra space.