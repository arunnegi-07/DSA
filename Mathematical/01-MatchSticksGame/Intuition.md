## Intuition 

**Few things to keep in mind to get the Intution behind the solution:**
1. A will always pick the stick first.
2. Both A and B can only pick sticks between 1 to 4 (inclusive).
3. Emphasize more on this : how many match stick **A** should pick in 1st try that **Guarantees the A's Win**.
 
**few things which I want you to know you in advance:**
1. If given **N** is divisble by 5, then no matter what **A** picks first it will always loose, in that case **return -1**.
2. if given **N** is not divisible by 5, then **A** always going to pick the last matchstick and the no. of stick which
    guarantees it's win will be calculated using **N % 5**, so we will return it as a answer.

Don't worry, we will see reason behind above points by taking some examples.

**Read the thought process behind it carefully and observe the examples carefully:**
``` 
In this problem, we have two players, A and B, playing the game of matchsticks. The goal of the game is to make
A the player who takes the last matchstick. The players can pick any number of matchsticks from 1 to 4 (inclusive) 
during their turn.

Now, let's analyze the problem to determine the optimal strategy for player A.

Observation 1: If the initial number of matchsticks (N) is divisible by 5, it is impossible for player A to win the game.

    Explanation: If N is divisible by 5, player A will always end up in a losing position, no matter how many matchsticks
    they pick. This is because, regardless of the number of matchsticks A picks, B can always mirror A's moves and ensure
    that he is the one who takes the last matchstick. Hence, in this case, the function should return -1 to indicate that it's
    impossible for A to win.

            Example :    let's  N = 10 (taking small example so it become easy to understand)

                    so A can pick anything from 1 to 4, so let us see all 4 cases :

                        1. if A picks only '1' stick at starting : 
                                
                                        so,  we left with 9 matchsticks.

                                Now, as 'B' also wants to win he will pick something which will ensure his win, so he knows if he
                                picks those many number of stick which will finally leave 'multiple of 5' ,then 
                                definitely it will make 'A' to pick at max '4' due to which eventually 'B' will be one to pick last.

                                so, 'B' will pick remaining (matchstick % 5)  i.e 9 % 5 = 4 matchsticks

                                        so ,  we left with 5 matchsticks.
                        
                            Now, if 'A' would have win if contraints was not of picking only 1 to 4 match stick, but as constraint
                            is there 'A' at max would pick '4',
                            if he do so we are left with only '1' matchstick and that 'B' will pick and win the game.

                    2. if A picks '2' stick at starting :

                                        so, left with 8 matchsticks.

                            Now, B will again do same he will pick 8 % 5 = 3 matchsticks.
                            
                                        so, we left with 5 matchsticks.

                            Now, same scenario happens as before, whatever 'A' picks 'B' will win.
                    
                    3. if A picks '3' sticks at starting :

                                        so, we left with  7 matchstick.

                            similarly B will pick 2 and we left with 5, and same thing goes here and 'B' will win.
                         
                    Same case will be there when 'A' picks 4 sticks.

    Note : If you dry run for other examples also you will get the same result. 
```
```
Observation 2: If the initial number of matchsticks (N) is not divisible by 5, player A can always force a win by picking a 
specific number of matchsticks on their first turn.

    Explanation: If N is not divisible by 5, player A can adopt a winning strategy. The key insight here is that player A wants
    to leave a multiple of 5 (5k ) matchsticks for player B after A's turn. By doing so, A ensures that no matter 
    how many matchsticks B picks, A can always mirror B's moves and leave B with a multiple of 5 matchsticks on 
    B's turn. This process continues until there is only one matchstick left, which A can then take to win the game.
   
                Example : let's N = 13

                    Now, we want guarantee the win of 'A', so it will do the same what B's was doing to win the game.

                    'A' will start by picking N % 5 i.e 3 in this case

                            so, we will left with 10 matchstick.
                    
                    Now, same thing due to which 'B' was winning will counter it's win because same scenario was there
                    for 'A' as he was starting and no. of match stick there were 'divisible by 5',and
                    here also after 'A' has picked 'N%5' matchsticks the matchsticks left are 'divisible by 5' and the chance
                    of 'B' is there.

                            so, isn't it the same scenario as before after 'A' picked 'N%5' matchsticks ?

                           Yes! same thing continue now, but as 'B' is starting this time (once it become '10' in this case
                           which is divisble by 5) it will definitely loose the game no matter what he picks next, as we have 
                           already seen earlier in detail. 
```

**Overall Conclusion:**
1. If N is divisible by 5 (N % 5 == 0), return -1 to indicate that it's impossible for A to win.
2. Otherwise, return N % 5, which represents the number of matchsticks A should pick on their first turn to ensure a win.

