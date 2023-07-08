## Intuition

As BruteForce method was taking O(N³) time, so to reduce it to O(N²) we are using this approach.

**So let us see what we are doing here :**
1. In BruteForce approach we were using **3** nested loops which was checking all the possible combinations of 
    **arr[i] + arr[j] + arr[k]**, but in this approach we will try to remove the **inner loop** which was used for value
    of **k**.
2. In this approach we will use the fact that, if we want **sum** of **3** numbers (let's say **a**, **b**, **c**) to be
    **zero** then, if we have **sum**  of first two numbers as **a + b**, then third number **c** has to be **-(a + b)**
    to make **sum** as **zero**.
    **For Example :** sum of first two numbers is **-6** then third number should be -(-6) = **6**, then **sum** of those
                                   triplets will be **zero**.
3. So we will use **2** nested loops to get the values of **first** and **second** numbers and using them we will calulate
    the **third** as **-(first + second)**, but 
    how we are going know if this **third** really exists in given array ?
4. So for that we will use a **unordered_set** to store **second** number in every traversal of **inner** loop, and if we 
    find that calculated **third** number in our **Set**, then we will return **true** indicating we got the **triplet**, else
    we will store the **second** number in the **set** and continue checking other numbers.

**Note :** We are using 'set' because we can search values in O(1) complexity so it will help in removing the 2nd inner nested 
loop. we can also use 'map' here but as we don't need 'key-value' pair so we will be using 'set'.

**Let's understand it using example :**
```
Let's take :
                arr[] = {0, -1, 2, -3, 1}
    
    Initially, Outer loop variable,  i  = 0
                  Inner loop variable,  j = i + 1 = 1
                  set will be empty initially.
    
    Now, 
           for i = 0 : 
                1. j = 1 :
                        so, third = arr[i] + arr[j] = arr[0] + arr[1] = 0 + -1 = -1
                        
                        so, we will see if '+1' was previously present in the array or not, for that to 
                        be checked we have to store value in the 'set' we are traversing i.e arr[j].

                        so, if we search in the 'set' for '+1' then we will not find it, it means till now
                        triplet is not present.

                        So we will increment the value of 'j' by '1'.
                       
                        Now, we will add the value of 'arr[j]' in our 'set'. --> set = { -1 }

                2. j = 2 :
                        so, third = arr[i] + arr[j] = arr[0] + arr[2] = 0 + 2 = 2  

                        Now, we will check if '-2' is already present before or not, for that we will check
                        in the 'set' for '-2'
                        but again '-2' is not present in the set.

                        so, we will add 'arr[j]' i.e '2' in the 'set'  -->  set = { -1, 2 }       
                
                3. j = 3 :
                        so, third = arr[i] + arr[j] = arr[0] + arr[3] = 0 + -3 = -3  

                        Now, we will check if '3' is already present before or not, for that we will check
                        in the 'set' for '3'
                        but again '3' is not present in the set.

                        so, we will add 'arr[j]' i.e '-3' in the 'set'  -->  set = { -1, 2, -3 }     
               
                4. j = 4 :
                        so, third = arr[i] + arr[j] = arr[0] + arr[4] = 0 + 1 = 1  

                        Now, we will check if '-1' is already present before or not, for that we will check
                        in the 'set' for '-1'
                        so, this time we will get '-1' inside the 'set'.

                        it means we got triplet whose sum will result as 'zero', so we will return 'true'.
    
    Note : If we still haven't found the triplet, we will continue for other iterations of 'i' but once inner loop was 
               completed we have to erase all the values inside the 'set' before starting the next iteration of outer loop,
``` 

**Note :** Just dry run same for other sample examples to get clear understanding of this approach. 