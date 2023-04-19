## Intuition :
**Time Complexity : O(NlogN)  and Space Complexity : O(1)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Sorting and Two Pointers.**

**Some Observations from the Problem :**
1. We have to calculate a Dominant pair(i,j), where ```0 <= i < n/2```, ```n/2 <= j < n```, ```arr[i] >= 5*arr[j]```,
   i.e **i** is from first half of the array and **j** is from the other half and pair is dominant only when value of
   array at **i** index is greater than 5 times of value at **j** index.
 
2. Array will always be **even**.

3. As we have to do our task in O(NlogN) we we cannot use the BruteForce method of checking every pair(i,j) it will
   take O(N*N) which will give Time Limit Exceed error.

**So, Let us see the better approach to reduce the Time Complexity:**<br>

**Example:**
  
    n = 6 
    arr = {10, 8, 2, 1, 1, 2}
     
    Step 1:
       1.a Sort first half part (from index '0' to index 'n/2'(excluded)),and
       1.b Sort Second half part (from index 'n/2' to index 'n'(excluded)).

       Reason: 
             1. we are sorting both parts separately because first half is for choosing 'i', and other for 'j'.
             2. This is done to make our calculation faster, we will see how when we dry run the example.

       After Sorting our array will be :  arr = {2, 8, 10, 1, 1, 2}
       
    Step 2:
       2.a Now, place 'i' at index '0' and 'j' at index 'n/2'.
       2.b Now, traverse the array until either 'i' crosses it's range (i.e i == n/2), or
            'j' crosses it's range (i.e j == n).

                                            i         j
                                            0  1   2  3  4  5  --> index
       Now, current situation is as :       2  8  10  1  1  2

    Step 3: Finding pairs
        Let us take a count variable and set it to zero --> count = 0
        Now, check if current pair is dominant or not,

            3.a                        arr[0] >= 5 * arr[3]
                                            2 >= 5*1 --> false
                                       therefore, pair(0,3) is not a dominant pair.

                    Now, here question is do we really have to check for other pairs (0,4) and (0,5) ?
                    So, Simple answer is No! we don't need to because the array is sorted in ascending order
                    and we know if value at 'arr[i]' is itself smaller than the smallest value of 'arr[j]'
                    then there is no chance that in future it will be greater than any of the value.
                    So, this is where Sorting is helping us in reducing the no. of operations.
                
                    So, count is still '0'.

                    Now, simply increment the value of 'i' and check for other values of arr[i].
                    
                                                    i      j
                                                    0  1   2  3  4  5  --> index
                    Now, current situation is as :  2  8  10  1  1  2

            
            3.b
                Now,                   arr[1] >= 5 * arr[3]
                                            8 >= 5*1 --> true
                                       therefore, pair(0,3) is a dominant pair.

                    But, here also we have one twist to save no. of operations and reason is same as array is 
                    sorted.
                    So, as array is sorted in ascending order therefore current 'arr[i]' value is smaller than
                    all the 'arr[i]' value which is to the right of it.
                    So, if smaller 'arr[i]' value satisfies the condition of domimant pair, then definitely all 
                    the remaining 'arr[i]' values from that point will also satisfy that condition.

                    So, we don't need to check that 'arr[j]' value again for other 'arr[i]' values and simply add
                    the count of those remaining 'arr[i]' into our answer.

                    So, we have --> 8 and 10 as 'arr[i]' values which satisfies the condition with arr[j] = 1.

                    therefore, count = 2.  

                    Now, keep 'i' as it is and move increment 'j' as for current value of 'arr[i]' we also have to
                    check other values of 'arr[j]' and now there is no need to bring 'j' back as we already have
                    added previous 'j' in our answer for all valid pairs.
                    
                                                       i         j
                                                    0  1   2  3  4  5  --> index
                    Now, current situation is as :  2  8  10  1  1  2

            3.c 
                Now,                   arr[1] >= 5 * arr[4]
                                            8 >= 5*1 --> true
                                       therefore, pair(1,4) is a dominant pair.    

                    So, as pair is valid again doing the same thing adding count of all the remaining 'arr[i]'
                    in our answer and increment 'j'.

                    So, count = 4.

                                                       i            j
                                                    0  1   2  3  4  5  --> index
                    Now, current situation is as :  2  8  10  1  1  2

            3.d 
                Now,                   arr[1] >= 5 * arr[5]
                                            8 >= 5*2 --> false
                                       therefore, pair(1,5) is not a dominant pair.             
                
                    So, increment 'i'.
                    and, count remains same as '4'.

                                                          i        j
                                                    0  1  2  3  4  5  --> index
                    Now, current situation is as :  2  8  10 1  1  2

            3.e  
                Now,                   arr[2] >= 5 * arr[5]
                                           10 >= 5*2 --> true
                                       therefore, pair(2,5) is a dominant pair.

                    So, we simply add the count of remaining 'arr[i]' values.
                    as only one value is remaining i.e '10' so we will add '1' to our answer.

                    So, count = 5.   

                    Now, increment 'j', but as soon as we increment 'j' condition become 'false' and
                    our process is ended and final value in count variable will be our answer.
 
#### So, this is the clear and in-depth explaination of my Intuition behind this Problem. 
        
**Note:** As we have discussed if we found the dominant pair then for that value of 'arr[j]' all other<br>
          value of 'arr[i]' from current 'i' are also become valid pairs as they are sorted in ascending order<br>
          So, for calulating the count of those all ```arr[i]``` use:
                                             ```count += (n/2 - i)```
                                         where ```i``` is current position of index 'i'.                          
