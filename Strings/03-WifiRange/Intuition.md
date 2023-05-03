## Intuition :
**Time Complexity : O(N)  and Space Complexity : O(1)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Based on Observation.**

**What Problem is saying:**
1. if S[i] == 1, means that ```ith``` room has a wifi and it is capable of providing the connection to all rooms at<br>
distance **X** to it's both sides.

2. We simply have to return **true** if all rooms will going to get the wifi, else return **false**.

**Few Observations:**
1. If there are some rooms availble (which do not contain wifi) to the left of a room having a wifi,
                                       For Example: 
                                                       00001.....(other rooms)
                                       here, 0000 --> are the 4 rooms that don't have the wifi,and
                                       after that '1' is the room having the wifi

   then given **X** should be greater than those no. of zeroes, then only we will proceed further otherwise we will stop and return
   **false** from here itself.           
                                      Let's say,
                                                  X = 4, then as no. of zeroes are also '4' that means 
                                                  that room is able to provide the wifi to all those 
                                                  room to the left of it (we are not worrying about right
                                                  rooms for now, we will see about it in 2nd observation)
                                                  So we can proceed further.
                                                  
                                                  But, if X < no. of zereos, means that room with wifi is 
                                                  unable to provide wifi to all the rooms to the left of it,
                                                  so we do not proceed further as not providing wifi to even 
                                                  a single room is itself a failure.
                                                  So, just return false.

 2. Now, If there is something like this '10000001....(other rooms)', i.e some rooms between '2' rooms having wifi, then
    check if 'no. of zeroes'should not be greater than **2*X** because this time both rooms will be involved in providing
    the signal.
    As the room having wifi has the capability to provide the signal to the room's at **X** distance both sides,therefore
    in this '10000001....(other rooms)', first '1' is capable of providing **X** distance to it's right and second '1' to
    it's left i.e  
                   If, in this example : '10000001....(other rooms)'   
                               X = 3 ---> means both rooms can cover upto 2*3 = 6 rooms between them 
                               So, in this case it will be true.

                               But, if X = 2 ---> then only '4' rooms will be covered, therefore return false.          
                                      
**Steps we will take:**
1. First we will take a variable ```distance``` and a flag varible ```flag_ones```, where ```distance``` variable is used to keep track 
   of 'count of continuos zeroes' (i.e count of continuos rooms don't have wifi) and ```flag_ones``` is a boolean variable which is set
   to **true** if we found '1' (i.e room having wifi), we will see how these varibales are used to make problem simpler.   

2. Just start traversing the given string from start till end, so for this we will take a loop.

3. if we have S[i] is a '0' we will make our ```distance``` increment by '1' that means we got a room with no wifi,but
   3.a if it is a '1' as well as ```ones_flag``` is currently **false** then set ```ones_flag = true```.
   3.b if it is a '1' but ```ones_flag``` is currently not **false** means '1' is also present before.

   Based on 3.a and 3.b we will perform some tasks to check if all rooms are getting wifi or not. 


**So, Let us see how above approach will work and what are the steps taken after 3.a and 3.b**<br>

**Example:**
    
    Let us take,
                S = 00100001001000100
                X = 2

      1. First we will take, distance and ones_flag variable as,
                           distance = 0 --> initially distance will be zero as we just starting.
                           ones_flag = false  --> means initially no 1's are found.
                        
               initially,
                            i      
                            0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0 
                            
      2. Now, if S[i] = 0, distance will be incremented by 1, so it is clear for first two zeroes distance will become '2',
                         so, 
                             distance = 2
                             ones_flag = false

                     Now,
                                i      
                            0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0                          

      3. Now, S[i] = 1 and ones_flag is 'false', then we will check if 'distance <= X' 
         So, in this case 2 <= 2 --> true 
         means current room is able to provide the wifi to all the rooms to the left of it.

      4. Now, we are sure that those rooms are definitely getting the wifi so we will proceed further and set the 'distance'
         back to Zero.
                    So, distance = 0 and ones_flag = true.

      5. Now, we will proceed furthera and count no. of zeroes until we found next '1', so after finding next situation will as:
                                   
                                          i      
                            0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0   

                     and, distance = 4  ones_flag = true

            But, this when we got '1' ones_flag was already set to 'true' means we have a situation where some rooms are present
            between the '2' rooms having wifi, so in that case we will check:

                             if, distance <= 2*X  --> in this case 4 <= 2*2 --> true 
                             therefore, we can proceed further.
      
      6. Same thing will be followed until the end till we have traversed the whole string.
         But, one final edge case is present there:
            
                             You can see at the end we have '2' Zeroes present after the last '1' and you know 
                             after every '1', we are setting distance = 0,
                             So, after last '1' those '0' will be in the counting and will make distance = 2

                             So, after coming out the loop we must have to check if any rooms are present at the 
                             end which do not have wifi and are they getting the wifi,

                             And, for that simply add a condition :  

                                             if(distance > X) --> means atleast one room is there which is not 
                                                                  getting the wifi, so return 'false'
                                             
                                             otherwise we will be sure that all rooms are getting the wifi and
                                             we will return 'true'.                       

##### So, this is the clear and in-depth explaination of my Intuition behind this Problem. 


**Note:** So we just have to take care of these below 3 situations :
<ul>
<li>000001</li>
<li>1000001,and</li>
<li>100000</li></ul>                       

        