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


**Prerequisite :**
```
    You should know have digit by digit multiplication works :

    Let us say we want to multiply : 567 * 8

    so   
```
**Let's Understand it with an Example :**
```
    Let us take N = 8
    and let's consider the vector to store the answer, intially we store '1' in it.
                                             
                                              0   --> index
                              result = {  1  }

    Now, we will start from '2' and we will go on till '8' (i.e N) as we know to calculate
    factorial we multiply numbers from '1' till 'N', same we will do here but using some
    different method.
   
    Let's say loop variable is 'x'.
    For x = 2 :

            So, for every variable 'x' of the outer loop, we will traverse our 'result' vector index-by-index
            from left to right i.e index '0' till the 'size - 1'.

            1. As for now only one value is there so inner loop will run only '1' time i.e for index '0'.
            2. we will multiply 'result[i]' with value of 'x' and store the result in some varible (let's say 'val')
                and also consider the carry if any (always intially it will be zero).
            
                            int val = result[i] * x  + carry
                                       = result[0] * 2 + 0  
                                       = 1 * 2 
                                       = 2 
            3. Now, we will calculate remainder of that



```   
      