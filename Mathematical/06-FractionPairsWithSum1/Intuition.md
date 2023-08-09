## Intuition:

**What problem we are Facing :**
So, in this Question the only problem we have to deal with are the fractions.  The main problem which we will face while
storing the Fractions and then compairing if their complement exists or not is the <b>precision</b>.
So, precision is the only thing which makes this problem fall into medium category when compared to problems like <b>2 Sum</b>
or <b>Find Pair sum</b>.

If we take example what we have in <b>2 Sum</b> :
```
  We have, arr = [1, 4, 2, 4, 6, 5]   target = 6
   and we have to return either the pairs which sum equal to target or we just need to
   return the respective indices of those pairs.
   
   Like here, (4, 2) (2,4) and (1,5)  are the pairs having sum equal 'target' i.e 6

   So, in this Problem we simply take, one value 4 (let's say) and to find it's another pair we 
   simply check if 'target - that value' i.e 6 - 2 = 2 --> this value is present or not,
   If for '4' we have '2' present in the given array we simply say that 'YES' pair is there.

    So, when direct integers are given doing arithmetic and doing comparision is simple, but in
    this given problem where we have fractions we will see what problems we will face.
```

Let's take one Example according to our Problem:
```
We have, 
        N = 4
        numerator = [1, 2, 2, 8]    
        denominator = [2, 4, 6, 12]

        Note : Respective index numerator[i]/denominator[i] is one fraction, so total 'N' fractions are given.

        Being a Human when we see this we can easily thing of the pairs of fractions which can sum to '1'.
        We thought like 1/2 + 2/4 = 1, and 2/6 + 8/12

        But when computer will compute this it will first perform divisions and then add them, you can see
        the difference in below example:

                                double x = (double)2/6;
                                double y = (double)8/12;
                                
                                if(x + y == 1)
                                    cout << "Hello" << endl;       --> This get's Printed
                                else 
                                    cout << "No Hello" << endl;
                                    
                                if(((double)(1) - y) == x)
                                    cout << "Hello" << endl;      
                                else 
                                    cout << "No Hello" << endl;    --> This get's printed
                                
                                cout << x << endl;    --> 0.333333
                                cout << (double)1 - y << endl;    --> 0.333333

            Some Weird Conclusions:
                1. Try running it and you will surprise to see that when we are adding these two fractions, then they
                    are giving sum exactly '1' (that's why BruteForce Method Worked), but
                2. When you take complement of each of them i.e if 1 - x == y (or)  1 - y == x , then this relation will
                    result false.
                3. Another Strange thing is when you print 'x' and '1-y' separately we will exact same result i.e 0.333333.
                   
        So, what getting us into this precision problem is doing that subtraction and so we will try to avoid doing it
        and find another way to do it.
```

**What we will do :**
1. First we will convert all the given fractions to their simplest form and doing this is very simple just take the fraction
    a / b (let's say), then take <b>gcd</b> of both of them and divide both <b>a</b> and <b>b</b> by that gcd.
    Example : **8 / 12**  --> gcd of 8 and 12 is '4' (largest number that divides both of them) and then 8 / 4 = 2 and 
    12 / 4 = 3  therefore, fraction become **2 / 3** which is at it's simplest form. 

2. Now, we will traverse over those fraction and for each fraction we will find it's complement but using some simple
    technique and without performing any divisions and subtractions (on doubles).

```
   So, if we take previous example :
        N = 4
        numerator = [1, 2, 2, 8]    
        denominator = [2, 4, 6, 12] 

    After simplifications they have become :
        numerator = [1, 1, 1, 2]    
        denominator = [2, 2, 3, 3]

    Observations :
        1. One thing you will notice is here is that the fractions which are possible to give sum as '1' are
            having same 'denominators'
            For example :  1/2 + 1/2 = 1
                                1/3 + 2/3 = 1

                    Note : Here, example is simpler that's why we getting sum '1', but there may be the case 
                               where sum is not equal '1'
                               like 1/4 + 5/4 = 6/4  not equal 1

                        So, having denominator same doesn't mean sum is definitely is '1', that's why I have 
                        said they are possible pairs not actual.

                So, this was the first Observation.

        2. When we get the "denominator" same, then to check if among those fractions which is my 
            correct pair, we will see which of those is having "numerator" as "denominator - numerator"
            of the fraction for which we are checking.
            Let's understand with an example :

                    For Example :  we got 1 / 3 now to check if any pair exists for this or not we will first
                                            check how many such fractions are their which are having denominator
                                            same as it, and in our example we have 2 / 3 as such fraction.

                                            Now, as our fraction is 1 / 3 now as denominators are same only thing
                                            which will define it sum adds up to '1' or not is "numerator" and by doing
                                            simple math we know that number is '2' because 1 + 2 = 3 and as soon 
                                            as numerator become 3 --> 3 / 3 = '1'.

                                            and how we get '2' --> 3 - 1 = 2, which I was talking about "deno - nume".

            These are the only steps we are doing to find count all the pairs of fraction that adds up to '1'.
```

But, I know for fraction **a / b** (let's say) getting such fraction whose "denominator" is same as 'b' and then for all such 
fractions getting those fractions whose "numerator" is "b - a", seems very complicated and tough, but trust me it is very
easy and getting this is just possible in **O(1)** time complexity with the help of a very beautiful Data Structure **Map**. 
We will achieve by storing our things in **Map of Maps**. 

**Note :** Refer to "Example" file to see the Example. 
