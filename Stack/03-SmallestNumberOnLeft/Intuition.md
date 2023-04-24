## Intuition :
**Time Complexity : O(N)  and Space Complexity : O(N)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Using Stack**

**Note : Before Reading the Intuition read the problem statement carefully and try to understand as much as you can.**

**Some Observations required to get the Intuition of the problem :**<br>
**1.** If Stack is 'empty' just 'push' the element inside the array and add '-1' to answer array.<br>
**2.** If 'top' of the stack is a 'smaller' element than coming element then definitely for coming element that 'top'<br> 
&emsp;element will be the nearest smaller element to it's left so add that 'top' element in your 'answer' array and just<br> 
&emsp;'push' that element into the stack.<br>
**3.** If 'top' of the stack is 'greater' than coming element then we know that element will never  be the nearest smaller<br>
&emsp;element to it's left so we will 'pop' all the element until we find the value which is less than it (not even equal).<br>
&emsp;&emsp;**3.a** If after 'popping' stack become 'empty' than 'push' that element in the stack and add '-1' to the answer array.<br>
&emsp;&emsp;**3.b** If some element is left inside the array then value at the 'top' will be the nearest smaller, so add that 'top'<br>
&emsp;&emsp;&emsp;&emsp;value to our answer array and 'push' that coming value into the stack.<br>
**4.** Repeat same Steps for all elements from start till last.

**Let me take one Example to make the Intuition clear**<br>

**Example:**
    
    Given:
      N = 9
      arr = 9 8 4 9 10 4 6 4 2    -1 -1 -1 4 9 -1 4 -1 -1

      Let's 'ans' array to store our answer ---> ans = {0,0,0,0,0,0,0,0,0,0,0}  ---> initially all zeroes
      Let's start from 9(starting element) till 2(last element)
      
        For i = 0 :
                                          |     |
                                          |     | --> as no one stack --> so 'ans' array at '0' index add '-1'
                                          |__9__|  
                 
 
                                   ans = {-1,0,0,0,0,0,0,0,0}

        For i = 1 :  
                                          |     |   pop 9    |     |
                                          |  8  |  ------>   |     |  --> as 8 is last so array at '1' is '-1'
                                          |__9__|            |__8__|  
                 
 
                                   ans = {-1,-1,0,0,0,0,0,0,0}  

        For i = 2 :
                                          |     |   pop 8    |     |
                                          |  4  |  ------>   |     |  --> same as before
                                          |__8__|            |__4__|  
                 
 
                                   ans = {-1,-1,-1,0,0,0,0,0,0}      

        For i = 3 :
                                          |     |       
                                          |  9  |  --> For '9', '4' is smaller so 'ans' at i = 3 become '4'
                                          |__4__|           
                 
 
                                   ans = {-1,-1,-1,4,0,0,0,0,0}     
        
        For i = 4 :
                                          |  10 |   
                                          |  9  |  --> For '10', '9' is smaller so 'ans' at i = 4 become '9'
                                          |__4__|      
                 
 
                                   ans = {-1,-1,-1,4,9,0,0,0,0}   
        
        For i = 5 :
                                          |  4  |      for '4' all       |     |       
                                          |  10 |  elements get popped   |     |
                                          |  9  |  ------------------>   |     |  --> so ans[5] = '-1' 
                                          |__4__|                        |__4__|  

 
                                   ans = {-1,-1,-1,4,9,-1,0,0,0}  

        For i = 6 :
                                          |     |   
                                          |  6  |  --> For '6', '4' is smaller so 'ans' at i = 6 become '4'
                                          |__4__|      
                 
 
                                   ans = {-1,-1,-1,4,9,-1,4,0,0}   

        For i = 7 :
                                          |  4  |                                |     |                     
                                          |  6  | ---> again all elements --->   |     | --> so ans[7] = '-1'             
                                          |__4__|      get popped                |__4__|                          
 

                                   ans = {-1,-1,-1,4,9,-1,4,-1,0}   

        Finally,
        For i = 8 :   
                                          |     |                                |     |                     
                                          |  2  | ---> again all elements --->   |     | --> so ans[8] = '-1'             
                                          |__4__|      get popped                |__2__|                          
 

                                   ans = {-1,-1,-1,4,9,-1,4,-1,-1}     ---> Final Answer


                              
**If you see the answer array and verify manually the nearest smaller elements to the left from a particular
        value you will get the same answer.**<br>
**So, run this for random sample arrays and you will get the Intuition Better.**                                                                            