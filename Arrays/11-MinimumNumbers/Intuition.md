## Intuition :
**Time Complexity : O(NlogN)  and Space Complexity : O(1)**<br><br>
**Read this till end you definitely going to get the intuition of the Best Approach.**

**Approach : Based on Observation**

**Question is Asking:**
1. We have to choose two indexes **i** and **j** such that value arr[i] is greater than and equal arr[j].
2. After that replace **arr[i]** with **arr[i] - arr[j]**.
3. Just Perform same task for every pair of **i** and **j** until single element is left in the array and
   remaining all are the zeroes and that value will be our answer and with that we have minimized the 
   value of the array as after that given operation will not be possible to perform.

**Some Observations from the Problem :**
1. From Constraints given it is clear that array contains only positive integer values.
2. If given array of **n** numbers always after completing all the operations minimum value of array is 
   **GCD of those 'n' number**.
3. So Final Observation is that we just know to find GCD of two numbers i.e **GCD(a,b)**, so Just we have 
   to run that method **n** times. 
   

    