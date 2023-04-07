#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force 
// TC : O(N^2)  SC : O(1)

```
// Function to calculate the count of special numbers
int countSpecialNumbers(int N, vector<int> arr){
    int ans = 0;
    // Iterate through each element in the array
    for(int i=0; i<N; i++){
        bool isSpecial = false;
        // Check if the element is divisible by any other element in the array except itself
        for(int j=0; j<N; j++){
            if(i!=j && arr[i]%arr[j]==0){
                isSpecial = true;
                break;
            }
        }
        // If the element is divisible by another element, increment the count of special numbers
        if(isSpecial){
            ans++;
        }
    }
    // Return the ans of special numbers
    return ans;
}
```
// Approach 2 : Using HashMap, Set and Sieve
// TC : O(N*M)  SC : O(N)

int countSpecialNumbers(int N, vector<int> arr) {
        map<int,int> freq;
        unordered_set<int> uniq;
        int max = 0;
        
        // In this loop we are doing 3 things
        // 1. calculating frequency of each element. 2. building set of unique elements. 3. finding max element.
        for (int i = 0; i < N; i++) 
        {
            freq[arr[i]] = freq.find(arr[i]) == freq.end() ? 1 : freq[arr[i]] + 1;
            uniq.insert(arr[i]);
            max = max > arr[i] ? max : arr[i];
        }
        
        // set to store special elements which will be part of our answer.
        // first we are checking out of those unique elements which are special ones.
        unordered_set<int> special;
        for(int z : uniq)
        {
            for (int i = 2 * z; i <= max;  i+= z)  //sieve method
                if (uniq.find(i) != uniq.end()) 
                    special.insert(i);

        }
        
        // variable to store our answer
        int ans=0;
        for (auto x : freq) 
        {   
            // if any number is repeating then adding count of that number directly to our answer
            // as that number will in that case a special number already.
            if (x.second > 1) 
                ans += x.second;
                
            // else we are checking our special number set and if current 'x' is special then incrementing 'ans' by 1
            else if (special.find(x.first) != special.end())
                ans++;
        }
       
       return ans; // finally returning ans
}

// Approach 3 : Using Sieve 
// TC : O(N*log(max))  SC : O(max element)

int countSpecialNumbers(int N, vector<int> arr) {
    // Find the maximum element in the input array
    int max=*max_element(arr.begin(),arr.end());
       
    // Create a vector to store the count of divisors of each number
    vector<int> mp(max+1,0);
       
    // Loop through each element in the input array
    for(int i=0;i<N;i++){
        int x=arr[i];
        // If the count of divisors of the element is already greater than 1, continue to the next element
        if(mp[x]>1)
            continue;
        // Otherwise, loop through the multiples of the element and increment their count in the mp vector
        else{
            for(int i=x;i<mp.size();i+=x){
                mp[i]++;
            }
        }
    }
       
    // Loop through each element in the input array and count the special numbers
    int ans=0;
    for(int i=0;i<N;i++){
        if(mp[arr[i]]>1) ans++;
    }
    return ans;
} 

int main(){
    // Sample inputs
    vector<int> arr1 = {2, 3, 6};
    vector<int> arr2 = {5, 5, 5, 5};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    // Calculate the count of special numbers for each input array and output the results
    cout << "Output for sample input 1: " << countSpecialNumbers(arr1.size(), arr1) << endl;
    cout << "Output for sample input 2: " << countSpecialNumbers(arr2.size(), arr2) << endl;
    cout << "Output for sample input 3: " << countSpecialNumbers(arr3.size(), arr3) << endl;
    return 0;
}                                                                                                                                                               
