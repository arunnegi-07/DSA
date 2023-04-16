## Intuition :
**Time Complexity : O(1)  and Space Complexity : O(1)**<br><br>

**Read this till end you definitely going to get the intuition of the Best Approach.**

So, if you see the Time complexity needed for this problem, it is ```O(1)```, that clearly indicates that we have to
just generate some formula in which just by putting value of ```N``` given to us will give us direct answer.<br>


**Before discussing the approach let us see few observations:**
```
1. For N=1:
    Here, Array will be {1} so it is already equal.
    
    Therefore, Ans : 0

2. For N=2:
    Here, arr[] = {1,3} 
    As, only two elements are there so taking i=0 and j=1,
    so, on applying A[i] += 1 and A[j] -= 1, we get
                       
                    arr[] = {2,2} --> All Array elements are equal.

    Therefore, Ans : 1

3. For N=3:
    Here, arr[] = {1,3,5} 

    first taking i=0 and j=2,
    so, on applying A[i] += 1 and A[j] -= 1, we get
                       
                    arr[] = {2,3,4} 
    
    Again, taking i=0 and j=2,
    so, on applying A[i] += 1 and A[j] -= 1, we get
       
                    arr[] = {3,3,3} --> All Array elements are equal.

    Therefore, Ans : 2

4. For N = 4 
   Here, arr[] = {1,3,5,7} 

    first taking i = 0 and j = 3,
    so, on applying A[i] += 1 and A[j] -= 1, we get
                       
                    arr[] = {2,3,5,6} 
    
    Again, taking i = 0 and j = 3,
    so, on applying A[i] += 1 and A[j] -= 1, we get
       
                    arr[] = {3,3,5,5}
    
    Again, taking i = 0 and j = 3,
    so, on applying A[i] += 1 and A[j] -= 1, we get
       
                    arr[] = {4,3,5,4}

    Now,taking i = 1 and j = 2,
    so, on applying A[i] += 1 and A[j] -= 1, we get
                       
                    arr[] = {4,4,4,4} --> All Array elements are equal.
   
    Therefore, Ans : 4
    
    Note : All these are minimum operations taken.
```

```    
if you observe for every array we are taking every value towards the median i.e
   For N = 3 --> arr[] = {1,3,5} ---> median = (1+5)/2= 3 --> so if we see above we have converted all values to 3
   For N = 4 --> arr[] = {1,3,5,7} --> median = (1+7)/2 = 8 --> so we have converted every value to 4
   similarly for N = 5 --> median = (1+9)/2 --> so we will convert all values to 5
   
   And also doing so will take minimum steps possible.
```

**Now, Let us Discuss O(1) Time Complexity Approach:**
```
We have discussed so much above to get directly to the actual logic behind O(1) approach:

Let us write actual scenario for N = 5 and N = 6 and finally we will derive the formula:

    N = 5(odd):               
                       0   1   2   3   4  --> index
                       1   3   5   7   9
                       |   |   |   |   |      Here, median = 5
                       V   V   V   V   V
                      +4  +2   0  -2  -4

                      We know, answer for this is '4 + 2' = '6'  --> which is nothing but sum of first N/2 even numbers.
                 
    N = 6(even):                
                    0   1   2   3   4   5 --> index
                    1   3   5   7   9   11
                    |   |   |   |   |   |     Here, median = 6
                    V   V   V   V   V   V
                   +5  +3   +1  -1  -3  -5

                     Answer for this is '5 + 3 + 1' = '9'   --> which is nothing but sum of first N/2 odd numbers.
     
    so, this problem doesn't even require a loop,
    Just do following things:
      1. if given 'N' is odd then return 'sum of first N/2 even numbers' 
            i.e (N/2)(N/2+1) --> just replaced N with N/2 in original formula. 
      
      2. if given 'N' is even then return 'sum of first N/2 odd numbers' 
            i.e (N/2)^2 --> just replaced N with N/2 in original formula. 

So Just apply single if else statement and get your answer in O(1).
```

**Note:** As Problem is expecting the answer in 'long long' so while calculating (or) returning the answer don't forgot typecast
          it in 'long long'.