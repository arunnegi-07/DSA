## Intuition 

**Let us first see few point to keep in mind:**
1. If we do **arr[i] = arr[arr[i]]** that is what question asking us to do then it will affect the original values
   and will produce the wrong result.
2. So keeping this in mind we know that we have to transform our array in such a way that we are able to retrieve
   back the original values somehow and all that we have to do in-place because expected space is O(1).
3. As from the problem it is clear values are **from 1 to n-1** so we will take advantage of that thing.

**Note:** For first time this method seems like it is hard to grasp but trust me by doing dry run yourself few
          times you are able to build the Intuition why we are doing so.


**Now, let us see the Approach by taking an Example:**
```
Let us take,    
            N = 5  arr = {4, 0, 2, 1, 3}

    
    So, we will do this in 2 steps, first we will transform our array and secondly we will do some small 
    operation on that and retrieve original answer.
```

**Step 1:**
```
    So, we will store the value for each index by doing some operations on it, we will add some extra value
    to them so that by removing them after we are able to get 2 things for let's say index 'i' :

        1. The value which was originally present at 'i'.
        2. The answer which needs to be present at 'i'.
 
    So how we will store the values in such a way let us see that:

        As values are from 1 to n-1, if we take mod(%) of any value with 'n' it will give us that
        value only.

        Now, see the mathematical formula we are going to use in step 1 :

                            arr[i] = arr[i] + (arr[arr[i]] % N) * N 

                    for now, don't worry about this formula we will see the reason behind it.
        
        Now, let us solve the example:

            For i = 0 :

                    arr[0] = 4 , so by formula the value at arr[0] will be transformed as: 

                            arr[0] = arr[0] + (arr[arr[0]] % 5) * 5
                            arr[0] = 4 + (arr[4] % 5) * 5
                            arr[0] = 4 + (3 % 5) * 5
                            arr[0] = 4 + 3 * 5
                            arr[0] = 4 + 15  --> 19

                Let's conclude few points from above calculations :
                    1. we are adding something to the original value, you can clearly see we are
                       adding to arr[0] i.e '4' some 15.
                    2. Second thing to notice is, that value 15 in above case is multiple of '5'
                       in general we are adding multiple of 'n' to the original value.
                    
                    Now, by analyzing for other indices we will see how it will help us in 
                    transforming our array in-place and getting the actual answer.
            
                Now, arr[] = {19, 0, 2, 1, 3}
            

            For i = 1 :

                    arr[1] = 0, so by formula the value at arr[1] will be transformed as: 

                            arr[1] = arr[1] + (arr[arr[1]] % 5) * 5
                            arr[1] = 0 + (arr[0] % 5) * 5
                            arr[1] = 0 + (19 % 5) * 5
                            arr[1] = 0 + 4 * 5    -->  see how doing (mod n) has given us the original value
                            arr[1] = 0 + 20       -->  storing the value back by adding factor of 'n' to it.
                            arr[1] = 20
                    
                Now, arr[] = {19, 20, 2, 1, 3}

           
        Overall Conlcusion :
            1. So, first we are doing 'mod n' to get the original value present at index arr[arr[i]], and
            2. then we are storing it by multiplying it by 'n' and adding it with arr[i] so that it will
               help in retrieving values further.

        Perform same calculation for other indices also and you will get your final Array as:

                        arr[] = {19, 20, 12, 1, 8} 
```                         

**Step 2:**
```
    we have, arr[] = {19, 20, 12, 1, 8} 

        Now, to get original answer just divide each values of array by 'n' i.e arr[i] = arr[i] / n,
        so we get :

                            arr[] = {3, 4, 2, 0, 1}
        
        One thing to notice is if you take 'mod n' of same array i.e arr[i] = arr[i] % n, then

                            arr[] = {4, 0, 2, 1, 3}

                        and which is our original array.
       
        So, this is because we have stored things in such a way by using mod and multiples that we are able
        to retrieve the values efficiently even though they are changed.
       
```

**Final Conclusion:**
1. To get the original values back for let's say **arr[i]**, we do **arr[i] %  n**.
2. To get our answer for let's say **arr[i]**, we do **arr[i] / n**.