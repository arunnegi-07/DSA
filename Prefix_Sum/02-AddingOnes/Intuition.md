## Intuition :

Brute Force is I think very Straight forward to apply in this problem, so let us see how we can apply
Optimized Approach. 

**Thinks to Understand:**
1. As we know, by reading the problem it is clear we are adding '1' to values **arr[i]** of given array **a[]**
   for each value of **updates[]** over the condition that **j <= i** (where, 'j' is value from updates[] and 
   'i' is the index of a[]).
2. We have to assume index **i** of **a[]** is **1-based indexing**.
3. In case of Prefix Sum every previous values propagates till end and we will take advantage of it.

**Now let us see one Example:**
```
n = 3 k = 4    --> 'n' is size of a[] and 'k' is size of updates[]
a[] = {0 0 0}  --> Initially all zeroes
updates[] = {1 1 2 3}

If we talk about BruteForce we were just picking up values from updates one by one and according
to the condition j <= i we are just keep on adding '1' to a[i] values and we got the answer.

But, in Optimized for every value in updates we just add '1' to first value only i.e if value we pick from
updates[] is '1' then add '1' (Note : Both '1' here are different) to a[1-1] = a[0] (subtracting '1' due to 
'1' based indexing) and then we will repeat the process for all other values.

Also Note : We just have to add '1' every time.

for updates[0] i.e '1':

        arr[1-1] += 1  --> arr[0] become '1'

        Current a[] -> {1, 0, 0}


for updates[1] i.e '1':

        arr[1-1] += 1  --> arr[0] become '2'

        Current a[] -> {2, 0, 0}


for updates[2] i.e '2':

        arr[2-1] += 1  --> arr[1] become '1'

        Current a[] -> {2, 1, 0}

for updates[3] i.e '3':

        arr[3-1] += 1  --> arr[2] become '1'

        Current a[] -> {2, 1, 1}

so, all Updates are done.

Now, just take prefix sum of final array 'a[]' and it will work same as we are adding '1' to every value
separately as it will propagate that sum to every value till end.

        so, currently a[] = {2, 1, 1}

        after, taking prefix sum --> a[] = {2, 3, 4}  --> Final answer

        Note: In prefix Sum we just starts from '1' index (not '0') and keep on doing a[i] += a[i-1]

```