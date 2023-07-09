/* Approach 2 : Using Set DataStructure 
    TC : O(N)  SC : O(N)

    Note : As we only want the smallest postive number missing, then if any number is missing it is definitely in the range 1 to N(size of array).
               Just consider below two arrays to make it more clear :
                    1.  arr[] = {-1, -3, 0, 1, 4, 3, 5, 2}  --> Here size is '8' 
                    2.  arr[] = {1, 2, 3, 4, 5, 6, 7, 8}     --> Here size is '8'

                        In 1st array all positive numbers which are missing from '1 to 8' are 6, 7 and 8
                        and smallest among them is '6', so it is our answer.

                        While, in 2nd array all numbers from 1 to 8 are present in the array, so if we want 
                        smallest positive number missing, then it will be '9' which is 'N+1'.

                So, overall conclusion is if we want our missing number it will be from '1 to N', if all number from '1 to N' are in the 
                array then definitely that number is 'N+1'.

            Also this little Observation will help us in understanding the Optimized approach for this problem, so keep it in the mind, you will get this
            observation clearly when we discuss those approaches.
    
    Again this approach is also simple, we just simply storing all the 'positive numbers' in the set (ignoring '0' and 'negative numbers').
    we are using set just incase repeated numbers are there it will count them as single.
    After that we just simply traverse over 'set' and check for numbers '1 to N', if any number is missing in this range then it would be our
    answer and if all the numbers from '1 to N' are present then our answer would be 'N+1'.
                                                                                                                                                                                                                                                                                    */

#include <bits/stdc++.h>
using namespace std;

//Function to find the smallest positive number missing from the array.
int missingNumber(int arr[], int n) { 
    unordered_set<int> numsSet;
    
    // Add positive integers to the hash set
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            numsSet.insert(arr[i]);
        }
    }
    
    // Check for missing numbers from 1 to N
    for (int i = 1; i <= n; i++) {
        if (numsSet.find(i) == numsSet.end()) {
            return i;
        }
    }
    
    // If no missing number found, return N+1
    return n + 1;
} 

int main() {
    // Sample input 1
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr1, n1) << endl;
    
    // Sample input 2
    int arr2[] = {2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr2, n2) << endl;
    
    return 0;
}