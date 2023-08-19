## Intution :
1. So Intuition for this approach is very simple, we just eleminate the extra time we were taking in the **Naive** Approach by checking 
    for every subArrays.<br>

2. Here, at every step starting from **0<sup>th</sup>** index till **last** we will keep on storing **prefixSum** along with the 
    corresponding position till which it is formed, we will see in the example how it will help us in knowing if any **subArray** whose **sum
    is equal** to given sum is present or not in just O(1) time.

3. Just one thing keep in mind, initially we will store **(0,0)** in our map, where first '0' is means **prefixSum** is **Zero** and second '0' means
    **position Zero**, as position starts from **'1'** (which is **0<sup>th</sup>** index position), so as usually there is no subArray like which 
    has **sum** as **'0'**, that is why we are just giving it a **position** which is before **'1'**, you can give it anything but just keep in mind 
    what you have given because while returning the correct answer it is necessary.
    But keep in mind we will see why it is necessary to add it.

4. Also Map we will be taking is a **unordered_map** which has **O(1)** time complexity of **insertion** and **searching** operation.

**Note :** Prefix Sum means "sum till particular point from left to right".

**Now, let's understand it using an Example :**
```
Let's take :
                    N = 5, S = 12   
                    A[] = { 1  2  3  7  5 }

        Initially Map will have (0, 0), let's name it 'prefix' :

                        prefix =>    key   :  value     
                                         {   0          0    } 

        and, we will initialize a variable 'prefixSum' and initialize it with '0'

                        prefixSum = 0
``` 

**For i = 0 :**
```
    A[0] = 1

            so, prefixSum = 1   --> it is due to { 1 }
    
    1. Now, with naked eyes we can tell that we are at the first position itself and only subarray 
        possible till now is {1} and it is definitely not equal to given sum 'S' i.e '12',
        But, we have to generalize it for all the positions like how we able to know standing at that
        position that if subarray is possible or not ?
    
    2. Now, think like that if we want to make 'sum' as '12' and till some point sum (which is prefixSum)
        is just '1' then how much short are we  to make our some as '12',
        definitely the answer is '11'.
        So, the idea is for every position we will find out if before that point is their any subArray occurred
        whose prefixSum is equal to 'prefixSum - givenSum'.

            Ex :  prefixSum = 1  S = 12
                   so, prefixSum - S = 1 - 12 = -11 
                
                which means if their is a subArray previously occurred whose prefixSum (Note this point, we are
                talking about prefixSum not sum), is '-11' then we will be sure that such array is present whose
                sum is equal to 'S'.
    
        If it is not clear don't worry just follow along and it will start becoming more clear and start making 
        sense when we do for i = 3. 

    3. For now we didn't get subArray having prefixSum as '-11', so we will store the subArray till the point
        we are at.

        So,  we will store prefixSum = 1 which is at position '1' inside our map.
    
                        prefix =>    key   :  value       
                                         {   0          0    }        ----> Updated Map 
                                         {   1          1    }
```

**For i = 1:**
```
    A[1] = 2

            Now, prefixSum = 1 + 2 = 3    --> it is due to { 1  2 }
    
    1. This time in our Map we will search for :
                    
                                    3 - 12  --> -9 
            and we know there is no prefixSum present in our array having sum '-9'
            
    2. So, we will store prefixSum = 3 which is at position '2'
    
                        prefix =>    key   :  value       
                                         {   0          0    }        
                                         {   1          1    }      ----> Updated Map
                                         {   3          2    }
```

**For i = 2:**
```
    A[2] = 3

            Now, prefixSum = 3 + 3 = 6    --> it is due to { 1  2  3 }
    
    1. This time in our Map we will search for :
                    
                                    6 - 12  --> -6
            Again no such sum is there.
            
    2. So, we will store prefixSum = 6 which is at position '3'
    
                        prefix =>    key   :  value       
                                         {   0          0    }        
                                         {   1          1    }      ----> Updated Map
                                         {   3          2    }
                                         {   6          3    }
```

**For i = 3:**
```
    A[3] = 7

            Now, prefixSum = 6 + 7 = 13    --> it is due to { 1  2  3  7 }
    
    1. This time in our Map we will search for :
                    
                                    13 - 12  --> 1
            And Yes! this time we will be able to find the a prefixSum 
            which is '1' inside our map.
            But what does it mean ? and how it is helping us in finding 
            our subArray ?  

            if you clearly observe, if we remove the prefixSum of '1' which is
            at position '1' from the prefixSum which is at current Position '4'
            i.e 13 
            we are getting exactly what we want i.e 13 - 1 = 12, that is why
            were calculating and storing prefix-sums

            and if you remove want the 'start' and the 'end' position of that
            subArray forming given sum, then 
                for start :
                            just add '1' to the position of the prefixSum we want 
                            to remove i.e in our case is position '1' 
                            therefore, start = 2
                
                for end :
                            The position we are standing currently is our end i.e
                            end = i + 1 {as position is 1-based indexing}
                            end = 3 + 1 = 4

                    If you pick the array having start = 2 and end = 4, then you will get :

                                                    { 2  3  7 }   --> sum is '12'

    4. so we will return both the indices.
```

**Note :** 
1. Make sure what you storing inside the Map, **index** or **position**, incase you are storing **index** in that case you 
    have to be careful at the end while returning the **start** position because then you have to do **+2** in it because 
    one for not considering the subarray whose prefixSum who have found and another due to **1-based indexing**, while
    in **end** you just have to add one due to **1-base indexing**.


Dry run the approach on your own on below examples to make above point more clear as well as to know why that initial
**(0,0)** was necessary to put :
1. A[] = { 1  2  3  7  5 }  and S = 7
2. A[] = {1,2,3,4,5,6,7,8,9,10} and S = 15
