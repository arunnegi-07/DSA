// Approach : Dynamic Programming --> Tabulation Method 
// TC : O(n*W) --> Nested for loops 
// SC : O(n*W) --> Space for 2-D table to store computations.

// In Tabulation Method we write a Iterative version of our Recursive code and also maintain the table
// to store computations of smaller units which helps in finding the final result.

// Here, first the Intialization of table is done based on the 'Base Condition' of the recursive program, and
// only first 'row' and first 'column' is filled based on the 'Base Condition' which is the samllest unit of the program.
// rest is filled after performing the further operations.

#include<bits/stdc++.h>
using namespace std;

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{  
    // Declaration of 2-D table 
    int dp[n+1][W+1];
        
    // intializing first row and first column of table
    // As Base case were for n==0 and W==0 profit was '0'
    // therefore, for first 'row' and first' column all values will be initialized with '0'
    for(int i=0;i<n+1;i++)
        for(int j=0;j<W+1;j++)
            if(i==0 || j==0) 
                dp[i][j] = 0;

    // We have Changed same recursive Program in Iterative version
    // As compared to recursive call here 'i' is in place of 'n' and 'j' is in place of 'W'
    // So, just replaced the --> max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1)) to wriiten code
    // in place of 'n-1' --> 'i-1' ; KnapSack(W-wt[n-1],wt,val,n-1) --> dp[j-wt[i-1]][i-1] (just ignore wt and val) and so on...
    for(int i=1;i<n+1;i++)
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }

    // We always got final answer at last cell, in this case i.e dp[n][W]            
    return dp[n][W];    
}

int main()
{
    // Sample Input 1
    int W1 = 50;
    int wt1[] = {10, 20, 30};
    int val1[] = {60, 100, 120};
    int n1 = 3;
    cout << "Sample Input 1" << endl;
    cout << "Maximum Value: " << (W1, wt1, val1, n1) << endl;

    // Sample Input 2
    int W2 = 50;
    int wt2[] = {10, 20, 30, 40};
    int val2[] = {60, 100, 120, 150};
    int n2 = 4;
    cout << "Sample Input 2" << endl;
    cout << "Maximum Value: " << knapSack(W2, wt2, val2, n2) << endl;

    // Sample Input 3
    int W3 = 10;
    int wt3[] = {5, 4, 6};
    int val3[] = {10, 40, 30};
    int n3 = 3;
    cout << "Sample Input 3" << endl;
    cout << "Maximum Value: " << knapSack(W3, wt3, val3, n3) << endl;

    return 0;
}
