## Inuition :

Let us see by taking an example what is the Intuition behind this approach and why even we are using this one.

As we have seen in BruteForce Approach when we have converted our given binary number to a decimal number then
we were getting the problem of **overflow** which was unable to handle by any of the data type, so now we will use
concept of **divisibility** to handle this problem and do it without getting overflow.

**First Let us see how series of power of 2 behaves when divisble by 3 :**
```
    Let us write power of 2's till 2^7 :

                            128         64           32         16          8           4           2           1
                            
                            if we divide '1' by 3, then we get remainder as :  1 
                            if we divide '2' by 3, then we get remainder as :  2 
                            if we divide '4' by 3, then we get remainder as :  1 
                            if we divide '8' by 3, then we get remainder as :  2 
                            if we divide '16' by 3, then we get remainder as :  1 
                            if we divide '32' by 3, then we get remainder as :  2 
                            if we divide '64' by 3, then we get remainder as :  1 
                            if we divide '128' by 3, then we get remainder as :  2 
                             
            So, we can clearly see when power of 2's are divisible by 3, they just produce the remainder either as 1 or 2, 
            more specifically 'odd' position gives remainder as '1' and 'even' position as '2'. 
```

**Now let us see how we use divisibility concept :**
```
    Let us say we want to divide :  
            
                            34 + 96 + 105  by '3', then in 2 ways we can do it :

                                1.  Adding all of them and then dividing by 3 :
                                                
                                            235 / 3  -->  as it not totally divisible by 3 so we get remainder as '1'
                                
                                2.  Another way is dividing each number separately and then addig remainder of all
                                    of all them and then dividing it by 3 :

                                            34 / 3  -->  remainder '1'

                                            96 / 3  -->  remainer '0'

                                            105 / 3 --> remainder '0'

                                            therefore,  (1 + 0 + 0) / 3  --> final remainder as '1'
                            
                           which means given sum is not divisible by 3.

    Same concept we will use to solve this problem so that there is no need to convert the given binary to
    decimal and we will easliy avoid the overflow.
```                                

**Let us see one Example how this will work :**
```
    Let us take : 
                                1 0 1 0 1 0 1 0 1   --> it's decimal equivalent is :   341 which is not divisible by 3
                                                                                       and remainder is '2'        

                                Now, we know there is no need to check for bit's which are zero because at the 
                                end they will not contribute to the sum.

                                So, we simply check if position is either 'even' or 'odd', as if it is 'odd' we will add '1'
                                else we will add '2', we have discussed this above why.

                                Now, 
                                we will start seeing position from right end to left because we take power of 2's from right
                                            
                                                  1        0        1        0        1       0       1       0       1 
                                                  |        |        |        |        |       |       |       |       |
                                                  1        2        1        2        1       2       1       2       1     

                                So we will add remainders only for those where bit is '1' :

                                                (1 + 1 + 1 + 1 + 1 ) / 3  =  5 / 3  --> which is not divisible by 3
                                                                                        and remainder is '2'  
```

So, just analyze it by taking some more examples by yourself and it will be more clear.
