// TC : O(N)  SC : O(1)

// Note : Refer to 'Intuition' file attached to get proper explaination behind this approach.

#include <bits/stdc++.h>
using namespace std;

int stockBuyAndSell(int n, vector<int> &prices) {
    int holdStock = prices[0];  // Assume the first stock is initially held
    int nextStock;
    int totalProfit = 0;  // Initialize total profit to 0
    
    for (int i = 0; i < n - 1; i++) {
        nextStock = prices[i + 1];  // Get the next stock price
        
        if (nextStock >= prices[i]) {
            // If the next stock price is greater than or equal to the current price,
            // it means the stock price is increasing or staying the same.
            // Continue to the next iteration of the loop.
            continue;
        } else {
            // If the next stock price is less than the current price,
            // it means the stock price is decreasing.
            // Calculate the profit from selling the stock and update the held stock price.
            totalProfit += prices[i] - holdStock;
            holdStock = nextStock;
        }
    }

    // Calculate profit for the last stock after the loop
    totalProfit += prices[n - 1] - holdStock;
    
    return totalProfit;
}

int main() {
    // Sample inputs
    vector<int> prices1 = {4, 8, 8, 7, 5, 6, 9, 6};
    int n1 = prices1.size();
    
    vector<int> prices2 = {10, 7, 5, 8, 11, 9};
    int n2 = prices2.size();
    
    // Calculate and print profits
    int profit1 = stockBuyAndSell(n1, prices1);
    int profit2 = stockBuyAndSell(n2, prices2);
    
    cout << "Profit 1: " << profit1 << endl;
    cout << "Profit 2: " << profit2 << endl;
    
    return 0;
}