## Intuition 

So, this problem looks very simple when we first read this problem because it just wants us to return the **sum of first 'n' natural numbers**.<br>
i.e we simply needsto do : **return n * (n+1) / 2;**

But we have to take care of given constraints also i.e  **0 <= n <= 10<sup>7</sup>**, so value of 'n' we are getting could be a very large value, so we have to take care of it.<br>
Also problem is also specifying : **answer could be very large, return answer modulo 10<sup>9</sup>+7**.

for that to make sure overflow does not happen : 
```
    Step 1 :
                we will convert our given 'n' to 'long long', 

                From this point onwards, any operations or calculations performed using the num variable will utilize the 
                long long data type, allowing for larger values to be handled without the risk of overflow.

    Step 2 :            
                Now, we just simply calculate the 'sum' as we do normally as : n * (n+1) / 2 

    Step 3 :
                Simply take mod (%) of that calculated 'sum' with 10^9 + 7 and return it. 
```

So, this problem was very easy but the thing we learned from here is how to handle the overflow situations.