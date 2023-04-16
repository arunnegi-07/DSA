## Intuition :
**Time Complexity : O(NlogN)  and Space Complexity : O(N)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Sorting and Logical Thinking**

**Note:** Before Reading the Intuition read the problem statement carefully and try to understand as much as you can.

So Intuition to this Problem is divided into two parts:
1. First we will find out if it is possible to make both given Arrays equal or not. 

2. Now, if it is possible then we will proceed further to calculate minimum number of operation required to do so<br>
   else we will return -1.<br><br>

**Some Observations required to get the Intuition of the problem :**
1. As only operations we can perform are either +2 or -2, so it is clear that we can only able to convert 
   an odd number to odd number and an even to even.

3. From problem statement and analyzing the examples given it is clear that:<br>
   one +2 operation and one -2 operation is considered to be as a Single operation.

4. Making Arrays equal is only possible when:<br>
    4.a Sum of Both Arrays are Equal.
        Ex-1 : A[] = {4, 5}
               B[] = {2, 7}

               so we can either convert A -> B (or) B -> A to make them equal, so let us do A -> B:

               As we have discussed odd is only convertible to odd and even to even so '5' is convertible to '7'
               and '4' is convertible to '2'
 
               so, operations to be performed on A[] are: 4 - 2 = 2 and 5 + 2 = 7 i.e now A[] = {2, 7} which is equal to B[]
               so, as we have discussed one +2 and -2 operation is considered as single operation 
  
               Therefore, total operation required is '1'.

               But, what about minimum operation required, so we will see that in Observation no.6
       
        Ex-2 : A[] = {6, 5}
               B[] = {1, 4}

               Here, to convert A -> B we need to perform '6 - 2 = 4' and '5 - 2 = 3' then further '3 - 2 = 1'
               so we got A[] = {4, 1} which is equal.
               But, is it correct According to given Problem Statement ?

               So, answer is No! beacause we need to perform '+2' and '-2' as a single operation while above we are 
               performing only '-2' which is not correct according to given statement.

               Also sum of both Arrays are not same which is another reason it is not possible to make them equal.

               Therefore, answer is '-1'.    
    
    4.b As odd is convertable to odd and even to even only so inorder to make array equal "Count of Odd and Even elements in both 'A'
        and 'B' should be equal"

5. This Observation is very Important to make this Problem simple and find minimum operation required:
     Ex : A[] = {1,7}
          B[] = {5,3}

          Let's convert A -> B : 
          
          let us convert 1 to 5 and 7 to 3
          so, for 1 : 1 + 2 = 3 --> 3 + 2 = 5
              for 7 : 7 - 2 = 5 --> 5 - 2 = 3

          so, A[] become : {5, 3} and operation needed are '2' because as already discussed one +2 and one -2 is considered as sigle.

          But is it Minimum one ? Let us see taking another way.
         
          Now, let us convert 1 to 3 and 7 to 5
          so, for 1 : 1 + 2 = 3
              for 7 : 7 - 2 = 5

          Now Operation required is only '1'.

          Therefore Answer is '1'.

          So how we came to know by which convertion we will get minimum answer:
          So, any values are converted to other value which is nearer to it i.e if you sort both Arrays 'A' and 'B',
          then converting it will take minimum no. of operations.

          so, in second case we have done the same, we have converted 1 to 3 and 7 to 5 i.e
          According to this A[] = {1,7} and B[] = {3,5}
          and you can clearly see both 'A' and 'B' are sorted. 

so keep all this observations in mind while we discuss one example to connect all these together.

**Let us see an Example to make it more clear:**<br>

**Example:**
    
    Given:
      N = 3
      A[] = {2, 6, 5}
      B[] = {1, 10, 2}
             
      Step 1: First Sort both Arrays 'A' and 'B':
           A[] = {2, 5, 6}
           B[] = {1, 2, 10}

      Step 2: Find Sum, EvenElements and OddElements in both 'A' and 'B'
           so, after applying this step we got :
              Asum = 13 ; Aodds = {5} ; Aevens = {2,6};  // Here, Aodds,Aevens,Bodds,Bevens are arrays to store elements.
              Bsum = 13 ; Bodds = {1} ; Bevens = {2,10};
            
      Step 3: Check if Sum of Both Arrays as well as A's and B's Odd and Even Counts are equal:
              if both are equal proceed to Step 4 else return -1.
      
      Step 4: Find Number of Minimum operations required:
              Let us maintain a 'ans' varible and set it to zero i.e ans = 0

              4.a: Let us First find for odd elements :
                   we have, Aodds = {5} and Bodds = {1}

                   No. of operations required to convert 5 to 1 is given as : abs(5 - 1) = 4 
                   taking abs because it may be possible to get negative if smaller number is present in Array 'A'
                   and no. of operations should not be negative.

                   But getting 4 means we are subtracting '1' 4-times to make '5' as '1', but according to questions we need to 
                   subtract 2 or add 2 each time.

                   Therefore dividing '4' by '2' we got actual answer as '2' (which is correct).  

                   so, for now 'ans = 2'    
              
              4.b: Now, finding for even elements:
                   we have, Aevens = {2,6} and Bevens = {2,10}

                   First converting 2 to 2 : abs(2 - 2) = 0 i.e operation needed to convert 2 to 2 is '0'.
                   so, ans = ans + 0 = 2 + 0 = 2. (adding to previous valueo of ans)

                   Now, converting 6 to 10 : abs(6-10) = abs(-4) = 4
                   as we have discussed divide it by 2 --> 4/2 = 2.
                   so, ans = ans + 2 = 2 + 2 = 4.

                   So, after performing all the operations we got 'ans' as 4, but this is not the final answer.
 
        Step 5: As we have discussed one +2 operation and one -2 operation is considered as one Single operation
                Therefore 'ans' obtained above has counnted them twice.
                So, to get final answer just divide it by '2' and return the final answer.

                Therefore Final answer ---> ans/2. 
                  
                 
Now, Just apply these 5 steps taking 2-3 examples to make this Intuition more clear.