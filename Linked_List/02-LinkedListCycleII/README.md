## Problem : Linked List Cycle II (Medium)

Given the ```head``` of a linked list, return the node where the cycle begins. If there is no cycle, return ```null```.<br>

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the ````next``` pointer. Internally, ```pos``` is used to denote the index of the node that tail's ```next``` pointer is connected to (**0-indexed**). It is ```-1``` if there is no cycle. **Note that** ```pos``` **is not passed as a parameter**.<br>

**Do not modify** the linked list.

**Example 1:**

        3 --> 2 --> 0 --> -4 ---     
              |________________|

```                       
Input: head = [3,2,0,-4], pos = 1

Output: tail connects to node index 1

Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

**Example 2:**

              1 --> 2---     
              |________|

```
Input: head = [1,2], pos = 0

Output: tail connects to node index 0

Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

**Example 3:**

               1 --> NULL

```
Input: head = [1], pos = -1

Output: no cycle

Explanation: There is no cycle in the linked list.
```  

**Constraints:**
<ul>
<li>The number of the nodes in the list is in the range <code>[0, 104]</code>.</li>
<li><code>-10<sup>5</sup> <= Node.val <= 10<sup>5</sup></code></li>
<li><code>pos </code>is <code>-1 </code>or a <b>valid index</b> in the linked-list.</li>
</ul>
 
**Follow up:** Can you solve it using ```O(1)``` (i.e. constant) memory?