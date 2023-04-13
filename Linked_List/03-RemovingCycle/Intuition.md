## Intuition :
**Time Complexity : O(N)  and Space Complexity : O(1)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Slow and Fast Pointers.**

So Intuition to this Problem is divided into two parts:
1. Is to check if Cycle Exists or not, As question is of removing the cycle so definitely cycle will be present.
   but we are doing it because it is the part of the solution and while doing so we placing ```slow``` and ```fast``` 
   pointers where we want them to be (we will see that where we place them when we discuss the Intuition).

   so, if both slow and fast pointers meet at some point we will break of loop and which indicates (i.e slow == fast)
   that cycle is present.

2. Then we will se the approach how we going to remove the cycle using those ```slow``` and ```fast``` pointers.<br><br>

Only two type of cases are present which we need to handle all the cases.<br><br>
**Let us see them one by one :**<br>

**Example 1:**
    Step 1:
         s,f  
          3 --> 2 --> 0 --> -4 ---     
                |________________|
        
        so at start 'slow' and 'fast' pointer will be at 'head', after applying cycle finding part 
        'slow' and 'fast' pointers will meet somewhere:

                            s,f
          3 --> 2 --> 0 --> -4 ---     
                |________________|
         
        this is the situation after 'slow' and 'fast' meets and this signifies that cycle is present 
        Note : Both pointers may meet anywhere in the list.

    Step 2:
        Now, we will set 'slow' pointer to head (i.e beginning of the list).
        
        Now, main part is here,
            we will move both 'slow' and 'fast' pointers one step at a time, till fast -> next != slow -> next, but why ?

        Let's first apply this in above list and then see what's going on :

        so, as soon as we set our 'slow' pointer to 'head' and apply while loop to move both pointers one by one till above
        mentioned condition becomes 'false', you can clearly see in below diagram, that condition become false in starting itself
        as fast -> next become equal to slow -> next.

          s                  f                            
          3 --> 2 --> 0 --> -4 ---     
                |________________|
        
        This indicates that 'slow' pointer is at the point after which cycle is starting so to remove cycle after coming out of the loop
        we just have to add fast -> next = NULL and cycle is removed.
        Now, final List will look like:
        
          s                  f                            
          3 --> 2 --> 0 --> -4 ---> NULL
        
        So if we take any Example of Linked List having a Cycle in then for every example, after we move our 'slow' and 'fast' pointer
        one by one in 'step 2' definitely they will Stop at same position as we have seen in above example.
        You can verify it taking different sample problems.

        Note: Expect '1' case above will work fine but for that we need to made small changes.

#### Now, Let's take another Case:
        
**Example 2:**<br>
    This is the Case when loop is starting from ```head``` itself and we will see what problem will come if we apply the same approach as 
    above here and then we will see what to add in our code in order to handle this case.

    Step 1:
         s,f 
          3 --> 2 --> 0 --> -4 ---     
          |______________________|
        
        so at start 'slow' and 'fast' pointer will be at 'head', after applying cycle finding part 
        'slow' and 'fast' pointers will meet somewhere:

         s,f
          3 --> 2 --> 0 --> -4 ---     
          |______________________|

        So,any Sample example if you take of this type where cycle is 'end-to-end' every time slow and fast pointer 
        will meet at the 'head'.  
        and this signifies that cycle is present 
        
        Now, if you apply step 2 same as before then what problem we will get let us see:

    Step 2:
        Now, as both 'slow' and 'fast' pointers are moving only by one step so this condition fast -> next != slow -> next
        will never going to be false and our loop will become infinte.
        So we don't want that, so to resolve this we will do this:

        After setting our 'slow' pointer to 'head' we will check if slow == fast  if still 'slow' is equal to 'fast' that
        signifies that both are at the 'head' and that cycle present is end-to-end.

        So, now to simply take a loop and iterate over our list by moving our 'fast' pointer one step at a time until it 
        reached the end and to know the end of the list we will use the condition : while(fast -> next != slow)
        this will stop the fast pointer exactly at the end.
        
        After doing so situation is like:
        
          s                  f                            
          3 --> 2 --> 0 --> -4 ---     
          |______________________|
         
        Now,
        we just have to add fast -> next = NULL after we come out of loop and cycle is removed.
        Now, final List will look like:
        
          s                  f                            
          3 --> 2 --> 0 --> -4 ---> NULL

        So after making this changes our approach will handle all the cases.

**Overall Conclusion:**<br>
  **1.** Set ```slow``` and ```fast``` pointer to ```head```.<br><br>
  **2.** Now, move ```slow ``` by one step and ```fast``` by two step until both meet at some point.<br>
  <!-- &emsp;&emsp;&emsp;**2.a**  **if** possible then return ```a + b + c```.<br>
  &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;**else** return ```-1```<br><br> -->
  **3.** set ```slow``` to ```head```.<br>
  &emsp;&emsp;&emsp;**3.a** Now, first check **if** ```slow == head``` which signifies cycle is end-to-end<br>
  &emsp;&emsp;&emsp;&emsp;&emsp;  then and we will do same as we have discussed in example 2.<br>
  &emsp;&emsp;&emsp;**3.b** **else** we will move both ```slow``` and ```fast``` one step at a time until<br>
  &emsp;&emsp;&emsp;&emsp;&emsp;    ```fast -> next != slow -> next```.<br><br>
  **4.** Set ```fast -> next = NULL```<br>
