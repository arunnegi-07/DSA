// Approach : Dynamic Programming --> Memoization
// TC : O(n*W) --> as we are now using Memoization so Computation will reduce drastically.
// SC : O(n*W) --> Space for 2-D Array to store Intermediate results
// This Solution may going to get TLE due to more strict time constraint due to more recursion and function calls
// So, Best Method to replace this Method is Tabulation Method.

// In Memoization Method we always use same program of Recursion just we add Memoization table to store already
// computed results and then using those results we reduce unnecessary recursive calls.
// Note : we always take our Memoization table based on variables which are changing, as in this problem value of 
// 'W' and 'n' changes for every recursion call so we take it as dp[W][n] or dp[n][W](then we can change our program accordingly).

#include<bits/stdc++.h>
using namespace std;

int f(int W, int wt[], int val[], int n,vector<vector<int>> &dp){
    // Base Case
    // If no items are available i.e n=0 (or) Knapsack not able to hold any weight i.e W=0
    // In both cases Profit will be Zero.
    if(n==0 || W==0)  return 0;

    // Checking if 'dp' array already have the required result
    // if not we will make the recursive call else we will return the required result
    if(dp[W][n] != -1) return dp[W][n];
        
    // if weight of any item is less than or equal to Weight of the Knapsack remaining
    if(wt[n-1] <= W)
        // we have two choices either to include it or not
        // if we are including then adding it's profit to our answer
        // else we simply going for next item
        // finally we are taking the one giving maximum profit out of those recursive calls
        return dp[W][n] = max(val[n-1] + f(W-wt[n-1],wt,val,n-1,dp),f(W,wt,val,n-1,dp));
    // if weight is more than Knapsack then do not include it(same like we have excluded item above)
    else
        return dp[W][n] = f(W,wt,val,n-1,dp);  
}
    
//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{  
    // 2-D vector to store intermediate results i.e 'dp' array
    // we have taken size of (W+1)*(n+1) and initialized it with '-1'
    vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
    // calling helper function 'f()' and returning the value computed at the end
    return f(W,wt,val,n,dp);
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
