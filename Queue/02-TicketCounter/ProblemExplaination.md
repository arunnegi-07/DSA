## Problem Explaination :

**What question is asking actually:**
```
    First tickets are given to first 'K' persons and after that we have to remove them all from the queue
    and then last 'K' persons will get the tickets, but most important point lies here i.e those 'K' peoples
    which are from last will get ticket from end, let us understand this with an example:

            N = 6  K = 3, then 
            queue = {1, 2, 3, 4, 5, 6}
                    
            In 1st distribution --> Chance of Front side :
                                    
                                    {1, 2, 3} will get the ticket and in this order 1 -> 2 -> 3
                                    and all of them will be removed.  
            
            Now, queue = {4, 5, 6}

            In 2nd distribution --> Chance of Back side :
                                    
                                    {4, 5, 6} will get the ticket but order will be 6 -> 5 -> 4
                                    i.e last person to get the ticket is '4'

                therefore, 4 is the answer.

    so, this thing we need to keep in mind while solving this problem and it will become easy to solve. 
```

