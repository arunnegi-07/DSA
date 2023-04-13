## Intuition :
**Time Complexity : O(1)  and Space Complexity : O(1)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

As no 3 consecutive characters should be same so we will take 2 characters at a time,
but which character to take first that we have to decide.
so we will choose the character with highest occurence and reason for doing so is that character with highest occurence
has the high possibility of having 3 consecutive occurence, and then we will add other two characters (b and c, if a is having 
highest count) between that character.

**Let us take few example how to do so:**<br>

**Example 1:** <br>
    ```a = 11```, ```b = 2```, ```c = 2```<br>
    Here, 'a' is having the highest occurence <br>
    so, ```aa _ aa _ aa _ aa _ aa _ a```<br>
    now we have to fill remaining characters one by one in those spaces.<br><br>
    so you can put them in any order, let us see one of the possibility:<br>
    ```aa b aa b aa c aa c aa _ a``` <br>
    so, as you can see to fill the last space there is no character left therefore 3 consecutive a's will be together,<br>
    which is not the correct.<br>
    Now, even if we check for other cases we will definitely going to get 3 consecutive a's.<br>
    so, ```Answer : -1```<br>

#### Let's take another example and then we will see what's going on behind,
        
**Example 2:**<br>
    ```a = 10```, ```b = 2```, ```c = 2```<br>
    Here, 'a' is having the highest occurence <br>
    so, ```aa _ aa _ aa _ aa _ aa``` <br>
    now we have to fill remaining characters one by one in those spaces.<br><br>
    so you can put them in any order, let us see one of the possibility:<br>
    ```aa b aa b aa c aa c aa```<br>
    so, now all the spaces are exactly filled by the remaining characters, therefore Answer will be sum of count of<br>
    all the characters because valid string will include all the characters.<br>
    so, ```Answer : 14```<br><br>
        
#### Now, let us see what's going on:
    if we see in Example 1: 
        we have max_count = 11 (i.e 'a') and no. of gaps as '5', that means in in order to make sure that no 3 consecutive 
        characters cannot be there we must have 'atleast' 5 characters remaining other then max_count.
        
        i.e remaining chracters count >= max_count 
        but, here we have only 4 characters remaining to fill in between that's why Answer is -1.
        
    But, if we see for Example 2:
        we have max_count = 10 (i.e 'a') and no. of gaps as '4', that means in in order to make sure that no 3 consecutive 
        characters cannot be there we must have 'atleast' 4 characters remaining other then max_count.     
             
        and we have 4 characters remaining so answer is '10+2+2 = 14'.
        
        So, only thing is if max_count is even then gaps are always n/2, but
        in case of odd max_count gaps are n/2.
        so, we have to check accordingly.
        
**Overall Conclusion:**<br>
  **1.** First just find max value among a, b, and c and that value will be contender of giving 3 consecutive characters.<br><br>
  **2.** Now, we just have to check if valid string is possible or not.<br>
  &emsp;&emsp;&emsp;**2.a**  **if** possible then return ```a + b + c```.<br>
  &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;**else** return ```-1```<br><br>
  **3.** To check whether string is possible or not:<br>
  &emsp;&emsp;&emsp;**3.a**  for **even** max_count check  --> **if**(```remSum``` >=``` max_count```/2-1)<br>
  &emsp;&emsp;&emsp;&emsp;&emsp;where, ```remSum``` is **'b+c'** (Let's say **'a'** is having ```max_count``` among all)<br><br>
  &emsp;&emsp;&emsp;**3.b**  for **odd** ```max_count``` check  --> if(```remSum``` >= ```max_count```/2)<br><br>
  
so, this problem is just about checking whether such string exists or not.