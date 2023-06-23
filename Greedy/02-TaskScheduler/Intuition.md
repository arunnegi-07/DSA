## Intuition
**Important:** Please carefully read the entire explanation, as this problem requires your utmost attention.

**Note:** 
1. We will see this problem Intuition using 3-4 examples and then we will reach to final conclusion, Also make sure you have 
    read problem carefully and understand what problem is trying to say.
2. First we will see manually the solution of each example and after doing some analysis will the generalize  it for all the cases.
3. See all the examples included to make everything clear as each examples contains something new and covers all the possibilities.

**Few things to keep in mind:**
1. CPU can repeat a task only after **atleast K** units of time has passed after it did same task last time.
2. only 1 unit is taken for every task.
3. least time  taken is either equal to total tasks given **i.e N** or it is greater than that but cannot be less than **N**.

**Example 1 :**
```
    Let's,  tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F','G'}
            N = 12  K = 2

        one possible order could be :  A  _  _  A  _  _  A  _ _  A  _ _  A _ _  A

                                       A  B  C  A  D  E  A  F  G  A  _  _  A _  _  A

                                   A  B  C  A  D  E  A  F  G  A  idle idle A idle  idle  A
        
        Note :
        1. There is a reason why I have written "A _ _ A _ _ A _ _ A _ _ A _ _ A" in starting and then inserted other tasks by
            meeting the condition that same task is repeated only after atleast 'K' units of time.
        2. As given value of 'K' is '2', this the reason why we have taken '2' spaces between 'A', and it follows the rule 
            that 'A' is repeated after atleast 'K' units of time.
        3. Also we have take the task having maximum count, as in this case 'A' is having count of '6' which is maximum
            among all and then we have placed other processes between them.
        4. After that we just placed remaining tasks and followed the rule that each task get repeated only after atleast
            'K' units of time.
        5. one thing to note is that as question says task can be repeated after alteast 'K' steps so instead of repeating 
            it after just 'K' steps we would have repeated them after any unit of time (let's say 5 unit), but the reason we
            are repeating just after 'K' is beacause questioned mentioned that we have to find 'least' or 'miminum' time
            to perform all the task, so doing so will give us the minimum time.

        Now, let us analyze what we have done :

                       A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

                       As each of them takes '1' unit of time, therefore totalTime = 16 unit (which is minimum time)

            Now, if you observe for this example, after we have taken 'A' which is repeated maximum number of times
            we reserved 'K' spaces between every 'A' for other remaining tasks to fit-in and if all those tasks are executed
            in that case CPU will remain idle.
            so, few observations are :
                  1. All A's will take '6' units of time as they are '6' in numbers and that we know is nothing but maximum
                     occurred task (let's say 'maxi').
                  2. Between those A's, total 'maxi - 1' i.e '6 - 1' = 5 gaps are there and in each gap we know we have taken
                      'K' spaces,
                                 therefore, total spaces = (maxi - 1) * K = (6 - 1) * 2 = 10 
                                 i.e 10 unit of time is taken by all the task that are placed between those A's.

                    if we add  both of them we will get = 6 + 10
                                                        = 16 units (same as we have seen above from diagram)
        
        For now conclusion is : 

                                    least time taken = maxi + (maxi - 1) * K  units    
        
        Note : This formula is not completed for now we have to see some more cases to complete it.
``` 

**Example 2 :**
```
    Let's,  tasks = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C'}
            N = 10  K = 2

        Here,  frequency of each task is : 
                                    A = 4
                                    B = 4
                                    C = 2

        Note :                 
        we can take any of 'A' or 'B' as both has maximum frequencies, and 
        Also note for example 2 there are total of '2' such tasks which has maximum frequency, and this is very helpful
        for us to add something new to our formula (we will see that by doing some analysis) 

        one possible order could be :  A  _  _  A  _  _  A  _  _  A     (A= 0, B = 4, C = 2)

                                       A  B C  A  B  C  A  B _  A     (A = 0, B = 1, C = 0)

            Now, we cannot put remaining 'B' in that space as we have to wait aleast 'K' unit, so CPU needs to be idle.
                                                
                                therefore,        A  B C  A  B  C  A  B idle A       (A = 0, B = 1, C = 0)

            Now, remaining 'B' will come at the end :

                                                  A  B C  A  B  C  A  B idle A B     (A = 0, B = 0, C = 0)


        Now, let us analyze what we have done :
                                                  A -> B -> C -> A -> B -> C -> A -> B -> idle -> A -> B

                As each of them takes '1' unit of time, therefore totalTime = 11 unit (which is minimum time)
      

        Now, if you observe for this example 2, then it is similar to example 1 expect that at the end we left with one 'B'
        let us see that :

                                                    { A -> B -> C -> A -> B -> C -> A -> B -> idle -> A } -> B
                                                
                                        here, between curly braces part we know how to calculate the time, it is given as :

                                                                maxi + (maxi - 1) * K --> 4 + 3 * 2 = 10 unit 
                                                                you can see inside braces total 10 tasks are there.

                                        Now, how can we generalise that '1' unit of 'B' ?
                                           for that please recall the thing which I have mentioned earlier that in example 2
                                           there are total '2' such tasks are there which are having maximum frequency,
                                           therefore,
                                                  if such tasks are let's say 'maxCount' is count of such tasks then total of
                                                  'maxCount - 1' tasks will always come to end and we just have to add
                                                  those units to our answer.
                                                                    
       Therefore, overall formula becomes :

                                        least time taken = maxi + (maxi - 1) * K  + (maxCount - 1) units    
        
        Note : 
            To make it more clear just dry run it by yourself.
```

**Example 3:**
```
    Last example to finalize everything :

                tasks = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'D'}
                N = 13  K = 2
                
                here, A = 4         Also, max = 4  and maxCount = 1
                         B = 3
                         C = 3
                         D = 3
            
            if, we use derived formula, then    

                                        least time taken = 4 + (4 - 1) * 2 + (1 - 1) 
                                                                   = 4 + 3 * 2 + 0
                                                                   = 10 units
                                        
                                        but is it correct ? let us see.
            
            We have already discussed at beginning that total time we get cannot be less than given value of 'N'.
            It is either 'N' or value bigger than that,

            therefore, final anwer will be as :
              
                            least time taken = max(N, maxi + (maxi - 1) * K  + (maxCount - 1));   ---> Final solution


           Now, let us see what is the possible solution for above example :

                                            A  _  _  _  A  _  _  _  A _  _  _  A  
                    
                    Here we have used one another rule which we have discussed that any task is repeated after
                    atleast 'K' units,
                    so till now we are taking only 'K' spaces but that will not work here because this time other 
                    processes are also large in number,
                    so to manage them we can take '3' spaces this time and which is perfectly valid as it is greater
                    than 'K'.

            So, final Solution :
                                            A -> B -> C -> D -> A -> B -> C -> D -> A -> B -> C -> D -> A           
```

**Note:** Just dry run by taking you own examples and everything will become clear.