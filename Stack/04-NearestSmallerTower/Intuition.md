## Intuition :
**Time Complexity : O(N)  and Space Complexity : O(N)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Using Stack**

**Note : Before Reading the Intuition read the problem statement carefully and try to understand as much as you can.**

**Some Observations required to get the Intuition of the problem :**<br>
**1.** This Problem is same as last one i.e **Smallest Number on Left**, just little difference is that now we have<br>
&emsp;to done same for the right side and finally select the nearest smaller out of that.
**2.** To find nearest smaller on right we simply just reverse the **for loop** we used to find left side nearest smaller.<br> 
**3.** One other thing which is different in this question is that, here in answer we have to add the **indexes** of the <br>
&emsp;nearest smaller element while in previous problem we have to add the actual value.<br>
So this is the only Observation here rest we have already covered in last problem.

**For this problem finding indexes of 'left' and 'right' nearest smaller will be simple, so we will focus on step after that.**<br>

**Example:**
    
    Given:
      N = 9
      arr = 9 8 4 9 10 4 6 4 2    
      
      So, After finding left and right nearest smaller we have : 
                                  
                                        0  1  2  3  4   5  6  7  8  ---> indices 
                                        9  8  4  9  10  4  6  4  2    

                               left = {-1  -1  -1  2  3  -1  5  -1  -1}   ---> these are indices

                               right = {1  2  8  5  5  8  7  8  -1}

           Let's say,initially   ans = {0  0  0  0  0  0  0  0  0}
                                
              For i = 0 :

                        left = -1  and right = 1   --> left = -1, means for arr[i], no element is present at the left 
                                                                  which is smaller than it,
                                                       right = 1, means right side at index '1' we have nearest smaller
                                                                  element than arr[i]          

                              therefore, we simply make : ans[i] = right[i].

                                              ans = {1  0  0  0  0  0  0  0  0}
              
              For i = 1 :

                        left = -1  and right = 2   --> same as previous step       

                              therefore, we simply make : ans[i] = right[i].

                                              ans = {1  2  0  0  0  0  0  0  0}

              For i = 2 :

                        left = -1  and right = 8   --> same as previous step      

                              therefore, we simply make : ans[i] = right[i].

                                              ans = {1  2  8  0  0  0  0  0  0}         

              For i = 3 :

                        left = 2  and right = 5   --> Now, we will check which 'index value' is nearest for arr[3],
                                                      so for that check absolute distance for both sides from arr[i].
                                                      so for, left : distance = 1  right : distance = 2  

                              therefore, we simply make : ans[i] = left[i].

                                              ans = {1  2  8  2  0  0  0  0  0}       

              For i = 4 :

                        left = 3  and right = 5   --> Same here as previous step.
                                                      so for, left : distance = 4 - 3 = 1  right : distance = 4 - 5 = 1  
                                                      as here distance is same so we will check for smaller value at both index
                                                      So, arr[left] = 9  arr[right] = 4 --> right is smaller 

                              therefore, we simply make : ans[i] = right[i].

                                              ans = {1  2  8  2  5  0  0  0  0}        

                        Similarly, if on checking for value it is also same then choose index which is smaller i.e  
                        for above case if values were also equal we will make arr[i] = left[i] as it is smaller than right.                                                                                                   
             
              Just Follow the same till i = 8 and you will get final 'ans' array as :

                                              ans = {1  2  8  2  5  8  5  8  -1}   
                                                             