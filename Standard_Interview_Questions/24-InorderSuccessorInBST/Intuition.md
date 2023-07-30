## Intuition 
    
Intuition behind this optimized solution is that, if we traverse our BST inorder then we get the sorted order.

**Example :**
```
For example we have :

                                      20
                                     /   \
                                   8     22
                                  / \
                                4   12
                                    /   \
                                  10   14    
    
    inorder traversal is : 4  8  10  12  14  20  22

    let's say given : x = 8 then clearly successive inorder value is 10 as it comes next to it.

    so it makes it clear that inorder successor of the 'Node x' will always be the leftmost value of
    all the nodes present on it's right i.e

                        x
                    4   8  ( 10  12  14  20  22 )   --> '10' is leftmost of all values on right.

    Now, how can we use property of BST to get this value :

    So, we simply start from 'root' and check :
         a. if current position value is greater than value of Node 'x' that means  it could be our answer
            (not sure at that point) so we will store it for now and move our pointer to left side (i.e curr -> left)
            because  now potential sucessor will be present on the left sub tree as current value is itself greater
            than 'x' so we need to come on left  so that we will be able to get the leftmost value which is greater to Node 'x'.
         b. but, if current position value is smaller or equal move to right (i.e curr -> right) because there is no chance to
            find the successor on left sub tree as it will be greater than 'x'.
         c. Repeat this step until 'curr' not become 'nullptr'.     
```

**Note :** Just dry run this for 2-3 sample examples it will become more Intuitive.