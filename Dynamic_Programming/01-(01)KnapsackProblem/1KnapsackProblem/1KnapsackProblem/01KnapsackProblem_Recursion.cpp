// Approach : Recursive Approach with no Optimization
// TC : O(2^n) --> as every item as two choices   SC : O(n) --> Stack Space for recursive calls
// This Solution definitely going to get TLE due to time constraint.

#include <bits/stdc++.h>
using namespace std;

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    // If no items are available i.e n=0 (or) Knapsack not able to hold any weight i.e W=0
    // In both cases Profit will be Zero.
    if(n==0 || W==0)  return 0;

    // if weight of any item is less than or equal to Weight of the Knapsack remaining
    if(wt[n-1] <= W)
        // we have two choices either to include it or not
        // if we are including then adding it's profit to our answer
        // else we simply going for next item
        // finally we are taking the one giving maximum profit out of those recursive calls
        return max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    // if weight is more than Knapsack then do not include it(same like we have excluded item above)
    else
        return knapSack(W,wt,val,n-1);
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
