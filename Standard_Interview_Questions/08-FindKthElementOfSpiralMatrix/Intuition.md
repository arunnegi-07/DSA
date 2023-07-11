## Intuition :

Approach is very simple just like traversing a Matrix, but instead of traversing it **row-wise** or **column-wise**, to traverse it **spirally** we will do it in 4 steps :
1. First we will traverse the **top** row.
2. Second we will traverse the **rightmost** column.
3. After that, we will traverse the **bottom** row.
4. Lastly, we will traverse the **leftmost** column.<br>
But instead of traversing whole matrix we just have to traverse only **k** times and return the value we are at after **k** traversals.

You can see the diagram below, the order in which we are traversing our matrix :

<img src="https://i.ibb.co/N2VsrHS/1689095279105.jpg" alt="1689095279105" border="0">

**Note :**
1. The stopping condition is : **rowStart <= rowEnd && colStart <= colEnd**.
2. But apart from that when given matrix is a **non-square** matrix then before doing the **3<sup>rd<sup>** step **i.e**
    traversing the **bottom row** we have to check if  **rowStart <= rowEnd** because not doing so will lead to unnecessary
    traversals.
3. Similarly, before **4<sup>th<sup>** step **i.e** traversing the **leftmost column** we must have to check if **colStart <= colEnd**.

After applying all these conditions and repeating those **4 steps** this approach will traverse any **square** or **non-sqaure** matrix **spirally** till **k** times and return that value.