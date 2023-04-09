## Problem : Linked List Cycle (Easy)

Given ```head```, the head of a linked list, determine if the linked list has a cycle in it.<br>

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the ```next``` pointer. Internally, ```pos``` is used to denote the index of the node that tail's ```next``` pointer is connected to. **Note that ```pos``` is not passed as a parameter.**<br>

Return ```true``` if there is a cycle in the linked list. Otherwise, return ```false.```

 
**Example 1:**

        3 --> 2 --> 0 --> -4 ---     
              |________________|

```                       
Input: head = [3,2,0,-4], pos = 1

Output: true

Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

**Example 2:**

              1 --> 2---     
              |________|

```
Input: head = [1,2], pos = 0

Output: true

Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

**Example 3:**

               1 --> NULL

```
Input: head = [1], pos = -1

Output: false

Explanation: There is no cycle in the linked list.
``` 

**Constraints:**
<ul>
<li>The number of the nodes in the list is in the range <code>[0, 104]</code>.</li>
<li><code>-10<sup>5</sup> <= Node.val <= 10<sup>5</sup></code></li>
<li><code>pos</code>is<code>-1</code>or a <b>valid index</b> in the linked-list.</li>
</ul>
 
**Follow up:** Can you solve it using ```O(1)``` (i.e. constant) memory?