**Let's see with an Example :**
```
    N = 6
    numerator     =  [ 2, 1, 4, 5, 2, 4, 5, 12 ]
    denominator =  [ 3, 3, 12, 7, 7, 9, 9, 27 ] 

    After simplification :
    numerator     =  [ 2, 1, 1, 5, 2, 4, 5, 4 ]
    denominator =  [ 3, 3, 3, 7, 7, 9, 9, 9 ] 

    Now, we will start traversing this simplified fractions :
        We will first define our map of maps as :
                unordered_map<int, unordered_map<int, int>> mp;
                Initially it will be empty.
            
            The outer map is used to group fractions based on their denominators (denominator), 
            while, The inner map stores the numerators of the fractions with a specific denominator.
            
            Let's see what final Map will look like then it become more clear.
```

<p align="center">
    <img src="https://files.catbox.moe/xyjibq.jpg" height="550" width="800">
</p>

```
    Above is the final result of the Map, which is keep on forming as we keep on checking for
    each possibilities, and
    Storing in such a way is helping us in checking the pairs in just O(1) time complexity.

    Let's discuss it for first "3" iterations and then we will end our discussion.

    1. For 2 / 3 :
   
        When 2 / 3 come it will search in Map, that is there any key present which is equal 
        to 3 (i.e denominator) or not, but we know as it is the first fraction so nothing is
        present inside the Map, so nothing is found.

        But, we have to store this fraction so that future fractions will know about 2 / 3 came
        previously.

        And, we can store it as:
                                           mp[3][2]++;

                which means for outer Map "key" is '3' i.e is "denominator" and for that Outer 
                Map with key '3', make a InnerMap (which is value for outerMap) with Key as "2"
                i.e "Numerator" and make it's value increment by '1'.
                which overall means:
                    We have '1' fraction whose denominator is '3' and numerator is '2'.
                    
        Note : Here it is important to understand how "key-value" pairs are linked to each other.

    2. For 1 / 3 :

        When 1 / 3, it will find in the map if there present any "key" having value as "3" and yes
        this time it will find it and in O(1).
        But after finding it will go inside it's "value" part, make sure to go inside the innerMap we
        have to refer the "value" part of outerMap.

        Now, inside that innerMap we will search for numerator with value 3 - 1 = 2 , as we have 
        discussed previously.

        And 'Yes' as we have stored it in iteration '1' so we got the pair therefore we will add the
        count of it in our answer, and why adding count because there may be case when same
        fraction is present 2 times, so we have to consider both of them, that's why we are storing
        count.

            therefore, pair found (1 / 3 , 2 / 3).


    3. For 1 / 3 :

        When 1 / 3, it will find in the map if there present any "key" having value as "3", this time
        again it will find it and in O(1).
        Again it will  go inside innerMap and search for numerator with value 3 - 1 = 2 .

        Similarly like previous we will get the pair as (1 / 3 , 2 / 3).
    
    So, in similar way whole process will work and finally you will get the count of all such pairs.
```

**Note :** Dry run yourself by taking some sample examples, it will help in grasping the Intuition more clearly.

**Conclusion:**
1. Step which is used to convert all the fractions into their simplest form calculates **gcd** to do so and whose time complexity
    is **O(logN)** and for **N** numbers overall complexity to do so becomes **O(N*logN)**.
2. After that finding pairs, first we traversed all the fractions which takes **O(N)** inside that just **O(1)** Map operations are
    performed.

    therfore, Overall TC = O(N*logN) + O(N) 
                                    ≈ O(N*logN)

3. About Space complexity it is **O(N)** for Map.
