## Intuition : 

Just two steps we are taking to count the numbe of bits which are '1' :
1. Keep on checking rightmost bit if it is '1' if it is then we will increase our count.
2. After checking it just shift the bit's of that number by 1 to right and next bit will be at the rightmost end and
    we will repeat the same step for that. 

We will repeat above 2 steps until number is greater than Zero.

**Here is quick Explaination how those 2 steps used will work :**
``` 
To know if rightmost bit of any number is '1' or not just simply do 'Bitwise AND' with '1'
                           
                           Ex :  N = 6   -->   when we do 6 & 1, it will be done as : 

                                                                       0 1 1 0    --> 6 binary equivalent
                                                                   & 0 0 0 1    --> 1 binary equivalent
                                                                       -------
                                                                       0 0 0 0    --> it's equivalent is ZERO, which implies 'last bit is not 1'

                           Ex :  N = 6   -->   when we do 5 & 1, it will be done as : 

                                                                       0 1 0 1
                                                                   & 0 0 0 1
                                                                       -------
                                                                       0 0 0 1    --> it's equivalent is ONE, which implies 'last bit is 1' 
                                                                        
                                                                        
        Now,  after checking rightmost bit just rigth shift the number by 1 bit so that we can check other bits also, for
        that we simply 'right shift' our number  using 'N >>= 1', it means right shift the number by 1-bit and update it.

                           Ex :  N = 6   -->   when we do 5 >> 1, it will be done as : 

                                                                       0 1 0 1 >> by 1- bit  -->   0 0 1 0  --> it's equivalent is '2'
                                                                                                                 (from leftmost-end '0' will be appended) 
                                                                                                                    
                                   Now, for next iteration this number will be checked.
```