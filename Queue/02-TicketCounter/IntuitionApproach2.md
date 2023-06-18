## Intuition:

**Let us see Intuition behind Approach 2:**

1. First thing to keep in mind which we already discussed in problem explaination i.e first we will start
   from 'front' and give tickets to first 'K' peoples and then we will start from 'back' and give tickets
   to last 'K' peoples but in reverse order and we will keep on doing this until we got our last person.

2. Now, as we want to do it in O(1) space complexity we must find a way to do it without using any extra 
   space, so for that as we know are thinking this problem in form of 'K' groups then why can't we take 
   use of it to solve the problem.
   So, let us see what are cases possible in doing so.


**Cases possible while forming groups :**

**Case 1 : If no. of groups formed are Even :**
```
    case 1.1 : none of the persons are left after forming the groups
  
        Example: N = 12  K = 3
                 
            so, queue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

                No. of groups(m) = N / K = 12 / 3 --> 4
                No. of people left(r) = N % K = 12 % 3 --> 0
                
                First let us see, manually who is the last person to get the ticket :

                    for 1st distribution : front chance

                        1, 2, 3 will get the tickets and order is : 1 -> 2 -> 3

                        and queue will become : {4, 5, 6, 7, 8, 9, 10, 11, 12}
                    
                    for 2nd distribution : back chance

                        10, 11, 12 will get the tickets and order is : 12 -> 11 -> 10

                        and queue will become : {4, 5, 6, 7, 8, 9}

                    for 3rd distribution : front chance

                        4, 5, 6 will get the tickets and order is : 4 -> 5 -> 6

                        and queue will become : {7, 8, 9}
                    
                    for 4th distribution : back chance

                        7, 8, 9 will get the tickets and order is : 9 -> 8 -> 7

                        and queue will become : {}

                    therefore last person to get the ticket is '7'    

            By simple Observation we will get the formula to get this in O(1) as :

                        lastPerson : (m / 2) * K + 1 (for this case)

                        if we put values which we have then,

                            lastPerson  =  (4 / 2) * 3 + 1
                                        =  2 * 3 + 1
                                        =  7

                            so we got the same result from formula also and formula is generated
                            by just observing same thing we are doing manually.  
```                    

```
    case 1.2 : some of the persons are left after forming the groups
  
        Example: N = 12  K = 5
                 
            so, queue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

                No. of groups(m) = N / K = 12 / 5 --> 2
                No. of people left(r) = N % K = 12 % 5 --> 2
                  
            By simple Observation we will get the formula to get this in O(1) as :

                        lastPerson : (m / 2) * K + r

                        if we put values which we have then,

                            lastPerson  =  (2 / 2) * 5 + 2
                                        =  1 * 5 + 2
                                        =  7

                            you can try we will get the same result if we manually do it.                   
```

**Case 2 : If no. of groups formed are Odd :**
```
    case 2.1 : none of the persons are left after forming the groups
  
        Example: N = 9  K = 3
                 
            so, queue = {1, 2, 3, 4, 5, 6, 7, 8, 9}

                No. of groups(m) = N / K = 9 / 3 --> 3
                No. of people left(r) = N % K = 9 % 3 --> 0
                  
            By simple Observation we will get the formula to get this in O(1) as :

                        lastPerson : N - (m / 2) * K

                        if we put values which we have then,

                            lastPerson  =  9 - (3 / 2) * 3
                                        =  9 - 1 * 3
                                        =  6

                            you can try we will get the same result if we manually do it.    
```                    

```
    case 2.2 : some of the persons are left after forming the groups
  
        Example: N = 8  K = 3
                 
            so, queue = {1, 2, 3, 4, 5, 6, 7, 8}

                No. of groups(m) = N / K = 8 / 3 --> 2
                No. of people left(r) = N % K = 8 % 3 --> 2
                  
            By simple Observation we will get the formula to get this in O(1) as :

                        lastPerson : N - ((m / 2) * K + r - 1)

                        if we put values which we have then,

                            lastPerson  =  8 - ((2 / 2) * 3 + 2 - 1)
                                        =  8 - (1 * 3 + 2 - 1)
                                        =  7 - 3 + 2 - 1
                                        =  5

                            you can try we will get the same result if we manually do it.                   
```

This are all the cases you need to keep in mind in order to get Intuition behind this O(1) space complexity solution.