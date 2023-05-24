## Intuition behind the given problem:

```
As question is asking us to find maximum bowls which contains equal of cookies.
    So, we just keep on dividing with Number of bowls (by decreasing it every time) to
    see for which 'N' it will be equally distributed.

    Let' say arr = {1, 2, 6, 5}  and N = 4;
    So, totalSum = 14 
    if, we check 
                for '4' bowls then 14/4  --> Not equally distributed
                for '3' bowls then 14/3  --> Not equally distributed
                for '2' bowls then 14/2 --> 7 i.e in '2' bowls candies are divided equally 

            therefore, maximum no. of bowls = 2 
```