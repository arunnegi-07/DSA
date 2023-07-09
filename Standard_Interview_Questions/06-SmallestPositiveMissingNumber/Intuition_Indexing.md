## Intuition :

**Indexing:** In Indexing approach we will take advantage of the property of the array indices to mark positive numbers as negative in order to identify the missing positive number. By marking the elements, we can distinguish between the presence and absence of positive numbers. This approach works effectively when each positive number appears at most once in the array.
You will get how it is working once we take one sample example and understand this approach over it.

**Before that few points you need to understand :**
```
1. As we only want the smallest postive number missing, then if any number is missing, it is definitely in the 
    range 1 to N(size of array).
        Just consider below two arrays to make it more clear :
            1.  arr[] = {-1, -3, 0, 1, 4, 3, 5, 2}  --> Here size is '8' 
            2.  arr[] = {1, 2, 3, 4, 5, 6, 7, 8}     --> Here size is '8'

                In 1st array all positive numbers which are missing from '1 to 8' are 6, 7 and 8
                and smallest among them is '6', so it is our answer.

                While, in 2nd array all numbers from 1 to 8 are present in the array, so if we want 
                smallest positive number missing, then it will be '9' which is 'N+1'.

                So, overall conclusion is if we want our missing number it will be from '1 to N', if all number from '1 to N'
                are in the array then definitely that number is 'N+1'.

2. Before performing actual indexing method over our array we first separate all the postive numbers towards left 
    and side and remaining negative numbers including '0' to the right side of the array, just by using a single loop 
    which will take O(N) time.

3. Now we will traverse our array from index '0' till the index where only positive numbers are present, and keep 
    on multiplying value at 'arr[i] - 1' with it '-1' indicating that the value which is having 'arr[i] - 1' as the the 
    correct position is present in the array.

4. After that we traverse our array and check for first non-negative number in same range where only postive 
    numbers were present, if we got a 'non-negative' number than it's 'index + 1' i.e 'i +1' will be the number 
    which is a smallest missing number, and
    if we did not found any non-negative number then it indicates that all positive numbers from '1 to N' are present
    and the smallest number which is missing is 'N+1'.

This points are not making much sense for now, but we will take one good example next to make it clear and 
understand the reason behind each step, like why we are making number as negative ?, why 'i+1' is our answer ?
and whatever other questions coming in your mind, example will make it more clear.
```

**Let us take an Example :**

**Step 1:** Separating postive number with other number :
```
    arr[] = {-1, 3, 0, 1, 4, -3, 5, 2}

    Note : Just Keep point '1' in your mind it will help in getting this approach more clearly.

    Separating postive number with other number :
                
                Doing so our array will be updated as :

                                0       1       2       3       4       5       6       7   ---->  indices
                               -----------------------------------------------                   
                arr[] =   {  3       1       4       5       2       -1     0       -3  } 

                so, now the range in which we have to check for missing number is '0' to '4'.
```

**Step 2 :** Start traversing from index '0' till '4' and keep on updating each number :
```        
    for i = 0 :
            Now, 'abs(arr[i]) - 1' : Why absolute ? we  will see it later. 
                    abs(arr[i]) -1 = abs(arr[0]) - 1 
                                         = abs(3) - 1
                                         = 2  
           
            so, value at arr[2] will be replaced with 'negative' of that number or we can say we
            will multiply it with '-1'.

            Now,
                           0       1       2       3       4       5       6       7   ---->  indices
                          -----------------------------------------------                   
            arr[] =   {  3       1      -4     5       2       -1     0       -3  } 
                         
            But what it indicates and why we are doing so ?
                                        
                As, we are checking for positive numbers 1 to N, so definitely '1' should be at index
                'zero' which means correct position of each number is 'number itself - 1', 
                similarly correct position of '3' is '3-1' i.e index '2'.
                therefore,
                                we will mark the value at that index as 'negative' of that number just to
                                indicate that number whose correct position is this is present in the array.

    for i = 1:
            Now, abs(arr[1]) -1 = abs(arr[1]) - 1 
                                           = abs(1) - 1
                                           = 0
           
            so, value at arr[0] will be replaced with 'negative' of that number or we can say we
            will multiply it with '-1'.

            Now,
                           0        1       2       3       4       5       6       7   ---->  indices
                          -----------------------------------------------                   
            arr[] =   { -3       1      -4     5       2       -1     0       -3  } 
                         
            which indicates that the value whose correct position is at index '0', which is 'index+1' = 0 + 1
            i.e '1' is present in the array.

            Note : 
            1. If for any value the 'abs(arr[i]) - 1' is going 'out of the bound' i.e in that case the index till which
                only positive numbers are present, then just ignore that iteration move to next.
            2. If value present at 'abs(arr[i]) - 1' is already 'negative' or '0' then also move to next iteration without
                making any changes. 
               
    for i = 2:
            Now, abs(arr[2]) -1 = abs(arr[2]) - 1 
                                           = abs(-4) - 1
                                           = 3
           
            so, value at arr[3] will be replaced with 'negative' of that number or we can say we
            will multiply it with '-1'.

            Now,
                           0        1       2       3       4       5       6       7   ---->  indices
                          -----------------------------------------------                   
            arr[] =   { -3       1      -4     -5       2      -1      0       -3  } 
                         
    for i = 3:
            Now, abs(arr[3]) -1 = abs(arr[3]) - 1 
                                           = abs(-5) - 1
                                           = 4
           
            so, value at arr[4] will be replaced with 'negative' of that number or we can say we
            will multiply it with '-1'.
         
            Now,
                           0        1       2       3       4       5       6       7   ---->  indices
                          -----------------------------------------------                   
            arr[] =   { -3       1      -4     -5      -2      -1     0       -3  } 
    
    for i = 4:
            Now, abs(arr[4]) -1 = abs(arr[2]) - 1 
                                           = abs(-2) - 1
                                           = 1
           
            so, value at arr[1] will be replaced with 'negative' of that number or we can say we
            will multiply it with '-1'.
         
            Now,
                           0        1       2       3       4       5       6       7   ---->  indices
                          -----------------------------------------------                   
            arr[] =   { -3      -1      -4     -5      -2     -1      0       -3  } 

```

**Step 3:** Traversing the array and checking for any 'non-negative' value from '0' to '4' :
```
    So, if we traverse from index '0' to  '4' then we are not going to get any 'non-negative'
    value and it is also valid because we can clearly for all the positive numbers from '1' to '5'
    whose correct positions are from index '0' to '4' are already present inside the array.

    therefore, the smallest positive integer which is missing is :
                if we assume 'p' as the index from where the next separation was starting 
                that is in our case index '5', 
                then the smallest positive number missing is : p + 1 = 5 +1 = '6'.
    
    Therefore, 
                    answer for our example is '6'.
```

**Note :**To make it more clear just dry run yourself for below provided sample examples:
1. arr[] = {1, -3, 0, 1, -4, 3, 5, 2}
2. arr[] = {1, 3, 1, 4, 5, 2}
3. arr[] ={1, 1}
4. arr[] = {-1, 3, 1, 4, 5, 2}
5. arr[] = {1, 2, 2, 3, 5, 5, 6}
6. arr[] = {1000000, 500000, 100, 10000, 5000}