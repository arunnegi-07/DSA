## Intuition :
1. The Idea of **Optimal** Approach comes itself from the **Naive** Approach, as in Naive way for every number we
    are again traversing the whole array and checking if all the elements on the **right** of it are smaller or not if we 
    found any value **greater than** it then we are not considering that element as the **leader**.

2. So this checking of all the elements was increasing our time complexity to **O(N<sup>2</sup>)**, so we have to 
    find the way so that there is no need of traversing again in order to find out if particular element is leader or not.

3. So, the Idea is Just **pre-calculate** the Maximum element on right for **each index**, but calculate from **right end** to the  
    **left end** because we want **greater on the right side** and it will just take **O(N)** time.

4. After that, for each starting from index ***'0'** till **end-1** (because last element will always be a leader), check if that value is  
    **greater than or equal** the **greatest value on right** of it or not (using pre-calculated values), if it is greater then we will be 100% sure 
    that no element is greater that it on the right so it is definitely a **Leader** so we will add it in our result.
    But if it is smaller than we will sure it is **not a Leader** because a leader have to **greater than** every element in it's right.

5. At the end just add the last value of the array also in the answer as it will always be a **leader**.


**See this Example :**
``` 
                    0    1   2  3  4  5 
        A[] = { 16  17  4  3  5  2 }

                                         0    1    2   3   4   5
        greaterOnRight = { 17  17   5   5   5   2 }

        For i = 0 : 16 >= 17  --> False  --> It is not a Leader

        For i = 1 : 17 >= 17   --> True  --> It is a Leader

        For i = 2 : 4 >= 5   --> False  --> It is not a Leader

        For i = 3 : 3 >= 5   --> False  --> It is not a Leader
        
        For i = 4 : 5 >= 5   --> True  --> It is a Leader
            
        And, the last element is always a Leader i.e 2

            Therefore, Leaders --> 17  5  2
```

**Note :**
Dry run yourself taking more examples to make this method more clear.