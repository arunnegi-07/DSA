## Intuition :
So, as you already know what is the problem in using the Naive approach of finding the **factorial** of a number, now
let us discuss what approach we will take and how that approach will help us to store and return very large result which 
was not possible in the Naive approach.

**Few Points :**
1. As **int** and **long long** data-types are unable to store the large results, so we will use the data structures which can,
    so we take string, array or vectors any of them for this task, but as problem itself has a return type of vector so we will go 
    with it.

2. So if we understand our approach in simpler manner what we will be going do, that insted of multiplying at once like we were
    doing in **Naive approach** like for factorial of '**10**' we were simply just taking a variable and starting from **'1'** we keep
    on multiplying number till **N** i.e **1*2*3*4*5*6*7*8*9*10**, this is the reason at some point of time **overflow** happened.

3. We will initially have **'1'** stored in our array as factorial of both **'0'** and **'1'** is **'1'** which is base case, so we will start 
    from **'2'** and go on till given **'N'**, and for every value of that loop (as initially it was **2**) we will multiply the number present
    in the array digit by digit instead of multiplying at once as we were doing in Naive approach, doing like that will help us in storing
    that number easily and then we will just return that number.

4. The number stored in the array after whole calculation will be in reverse order, so before returning it we have to **reverse** the whole
    array back and then return it.
    I know above points are not making any sense to you for now, but I just want to give you a brief overview what we will be going to do
    in this approach, all these things will become crystal clear as we take an example next.

**Note :** Before moving to Example if you don't know about how we do **digit by digit** multiplication, then in same folder you will
find **prerequisite** file attached, see that before going to example.


**Let's Understand it with an Example :**
```
    Let us take N = 5
    and let's consider the vector to store the answer, intially we store '1' in it.
                                             
                                              0   --> index
                              result = {  1  }

    Now, we will start from '2' and we will go on till '5' (i.e N) as we know to calculate
    factorial we multiply numbers from '1' till 'N', same we will do here but digit by digit.
   
    Let's say outer loop variable is 'x'.
```

**For x = 2 :**   
```
    So, for every variable 'x' of the outer loop, we will traverse our 'result' vector index-by-index
    from left to right i.e index '0' till the 'size - 1'.

    1. for now only one value is there in our 'result' vector so inner loop will run only '1' time 
        i.e for index '0'.
    2. we will multiply 'result[i]' with value of 'x' and store the result in some varible (let's say 'val')
        and also consider the carry if any (always intially it will be zero).
    
                    val  = result[i] * x  + carry
                            = result[0] * 2 + 0  
                            = 1 * 2 
                            = 2 

    3. Now, we will calculate remainder and carry for that 'val' :

                    rem =  2 % 10 = 2
                    carry = 2 / 10 = 0
    
    4. Replace the value of result[i] with value of 'rem' :

                    result[i] = result[0] = rem = 2 
                
                                        0   --> index
                i.e   result = {  2  }   --> which is factorial of '2'

Note : Important thing to note here is in every step factorial of 'x' is getting calculated 
in the inside loop, as here for x = 2 at the end in the 'result' we got value of factorial of
'2' , that is why outer loop is going till 'N' because at the end factorial of 'N' will be stored
in the vector.
```
 
**For x = 3 :**    
```
    1. Again 'i' will go from '0' till 'size-1' of 'result' vector, and this time also only one value is there.
    2. we will multiply 'result[i]' with value of 'x' and store the result in some varible (let's say 'val')
        and also consider the carry (this time also carry = 0).
    
                    val  = result[0] * 3  + 0 = 2 * 3 = 6

    3. Now, we will calculate remainder and carry for that 'val' :

                    rem =  6 % 10 = 6
                    carry = 6 / 10 = 0
    
    4. Replace the value of result[i] with value of 'rem' :

                    result[i] = result[0] = rem = 6 
                
                                        0   --> index
                i.e   result = {  6 }   --> which is factorial of '3'
```    
 
Similarly,
**For x = 4 :**    
```
    1. val  = result[0] * 4  + 0 = 6 * 4 = 24

    2. Now, we will calculate remainder and carry for that 'val' :

                    rem =  24 % 10 = 4
                    carry = 24 / 10 = 2
    
    3. Replace the value of result[i] with value of 'rem' :

                    result[i] = result[0] = rem = 4 
                
                                        0   --> index
                i.e   result = {  4 }   --> which is factorial of '3'    

    But,this time after multiplication is completed, carry is not '0' so we have
    to add it in our result :

    4. So, what we will do we keep on dividing it by 10 and attach the remainder
        in the result i.e

            rem = carry % 10 = 2 % 10 = 2
            
                                    0   1    --> index
            so,   result = {  4 , 2 }      

            carry is updated to ---> carry / 10 = 2 / 10 = 0 i.e now carry is '0'

        so, for this Iteration :
                                    0   1    --> index
                    result = {  4 , 2 }   --> which is factorial of '4' (but in reverse)
```                        
      
Finally,
**For x = 5:**
```
    Now, inner loop run for '2' times as 'result' vector is now containing '2' digits.
                                                    0   1    --> index                              
                                    result = {  4 , 2 }

    For i = 0 :           
        1. val  = result[0] * 5  + 0 = 4 * 5 = 20

        2. Now, we will calculate remainder and carry for that 'val' :

                        rem =  20 % 10 = 0
                        carry = 20 / 10 = 2
        
        3. Replace the value of result[i] with value of 'rem' :

                        result[i] = result[0] = rem = 0 
                    
                                        0  1     --> index
                i.e   result = {  0  2 }  

    For i = 1 :           
                    This time carry = '2'

        1. val  = result[1] * 5  + 2 = 2 * 5 = 12

        2. Now, we will calculate remainder and carry for that 'val' :

                        rem =  12 % 10 = 2
                        carry = 12 / 10 = 1
        
        3. Replace the value of result[i] with value of 'rem' :

                        result[i] = result[1] = rem = 2 
                    
                                        0  1     --> index
                i.e   result = {  0  2 }  

    Now, again after completeting the multiplication, we have carry left i.e '1'

    4. So, what we will do we keep on dividing the carry by 10 and attach the remainder
        in the result i.e

            rem = carry % 10 = 1 % 10 = 1
            
                                    0   1   2    --> index
            so,   result = {  0   2   1 }      

            carry is updated to ---> carry / 10 = 1 / 10 = 0 i.e now carry is '0'

        so, for this Iteration :
                                    0   1    2 --> index
                    result = {  0    2   1 }   --> which is factorial of '5' (but in reverse)  
```       

So, This is how we calculated the Factorial for Large Numbers efficiently. Just dry run yourself by taking some values
of 'N' to make this method more clear. 