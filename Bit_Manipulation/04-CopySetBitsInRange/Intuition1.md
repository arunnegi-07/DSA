## Intuition :

Let us see how actually Approach 2 is working and what al concepts are used here :

**What problem want us to do :**
we have a range represented using **l** and **r** (**Position starting from 1**) and for that range we have to set bits of **X** for all
bits which are set in **Y**.

**Things we are dealing with here :**
1. Concept of Checking if bit is set or not. 
2. Right shift operation.

**Note :**
1. We are not directly Setting the bits of 'X' for the positions where 'Y' bit is set, but we keep calculating the sum of
    power of 2's, for positions where 'X' bit is '0' and at the same time 'Y' bit is '1'.
2. After that we just add that 'sum' to given 'X' and we will get our final answer.
   
**Let us take an example to see how we going to approach the problem :**
```
            X = 44, Y = 89
            L = 2,  R = 7
            
                44  -->  0 0 1 0 1 1 0 0   

                89  -->  0 1 0 1 1 0 0 1
            
            Note : 
            1. We are going always working on rightmost bit always.
            2. Range is '1-based indexing' and start from right side.

            Step 1 :  As we want to check 'Y' for set bits and set those bits in 'X' for same positions 
                          for the range  l to r, for that we will right shift both the numbers till the start of
                          the range :
                          and we will also maintain a variable 'pos' to keep track of position we are currently
                          at so that we can calculate the 'sum'.
                           
                          both number are right shifted by 'l -1' i.e 2 - 1 = 1
                          and 'pow' is initialized to 'l-1' i.e '1' because our range is l to r.

                                0 0 1 0 1 1 0 0 ---> now becomes --> 0 0 0 1 0 1 1 0  (X) 

                                0 1 0 1 1 0 0 1 ---> now becomes --> 0 0 1 0 1 1 0 0  (Y)
                                                    
                                    you can clearly see right shift by 'l-1' bits

            Step 2 : Now, we just check for each positions from left, if bit of 'Y' is '1'
                         and bit of 'X' is '0', then we just make that bit of 'X' as '1'.                

                         so, to know if rightmost bit is set or not we just perform 'Bitwise AND' with '1' :

                            Ex :  if we want to check : 0 0 0 1 0 1 1 0 

                                                0 0 0 1 0 1 1 0 
                                            & 0 0 0 0 0 0 0 1
                                            --------------------
                                                0 0 0 0 0 0 0 0   
                                            --------------------
                                which is equivalent to Zero means rightmost bit of number is not set.
                                if it result in '1' then it means rightmost bit is set.
                
                    For our problem we just need to check :

                            if( !(X & 1) && (Y & 1)) 
                                which means we are checking rightmost bit of both 'X' and 'Y' and if 
                                last bit of 'X' is '0' and at the same time 'Y' IS '1' then it means we have
                                to make corresponding bit of 'X' as 1,
                                which means we have to add pow(2, pos) i.e 2^pos to 'sum'

            Step 3 : Now, after that we simply right shift both values by '1' to so that next bits are
                         now at the rightmost positions and we can perform same operation on that
                         until we have checked for entire given range.

    Now, let us see what our example results if we perform the above steps on it :
                                     
            X --> 0 0 1 0 1 1 0 0                Y --> 0 1 0 1 1 0 0 1 

            After 'l-1' right shifts i.e '1' : 
            I have also written range of the each bit (not actual positions)
                                 
                                    9       8       7       6       5       4       3       2
                                   ----------------------------------------------
        updated  X  -->    0       0       0       1       0       1       1       0  

        updated  Y  -->    0       0       1       0       1       1       0       0  
                                                    ...............................................................   
                                        dotted line indicates the range we have check for. 
                       
                Now, we can clearly see for position '5' and '7', we are having 'X' as '0'
                and 'Y' as '1' :

                    so, when we check one by one each bits then only for these two bits
                    we are going to add up the weights to our sum, let us see how :

                            for position '5' :
                                weight is 2^4 (it is 0-based indexing, 1-based was the range)
                                i.e sum += 16 = 16
                            
                            for position '7' :
                                 weight is 2^6  i.e sum += 64 = 16 + 64 = 80
             
            therefore, the final answer will be :  X + sum = 44 + 80 = 124
            you can confirm it by changing bits of 'X' to '1' where bits of 'Y' are '1' for
            given range and converting it to decimal you will get the same result.

    Note : Before performing operations on 'X', store it's copy as we want to add value
               of 'sum' to it to get the final answer. 
``` 

**Note:** Just dry run it by taking your own sample examples. It will become clearer, and doing the analysis yourself will help you learn something new that you might have missed in the explanation.
