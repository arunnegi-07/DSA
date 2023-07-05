## Intuition : 

The goal is to maximize the total profit by buying and selling stocks. The approach is to iterate through the prices of stocks and calculate
the maximum profit we can get by buying or selling the stocks.

**Things to understand:**
1. The Intuition works the exact similar way like a stock market, here also we will take the same approach we take while
    buying and selling stocks in the stock market.
2. We will try to buy stock at minimum price and sell it at higher price possible till market goes down again.
3. Also according to question at a time we can hold only single stock.

**See below example :**
Let's consider the example input :  
        prices = {4, 8, 8, 7, 5, 6, 9, 6}   --> for 8 days
        
1.  Intially we will buy and hold a stock when price is at '4'.
2. After that we will check next price until it is maximum, and we can see till 3rd day stock prices are gone maximum i.e 8,
    but after that it fall to 7, therefore we will sell our stock on day 3, and earn a profit of :

                                profit = 8 - 4 = 4

3. Now, as we sold the stock which we were holding now we can buy new stock i.e of price '7'.
4. Now, as we proceed further we found that prices are falling down to '5', so we will sell that stock with price '7' at same 
    price only because selling it at '5' will lead to loss :
                                
                                profit = 7 - 7 = 0

5. Now, we will buy stock at price '5'  and keep holding it until price of stocks are rising and we can see for day '6' and '7'
    prices are increasing, so we will sell our stock of price '5' on day 7 at price '9' :

                                profit = 9 - 5 = 4

6. Finally, on day '8' we will buy and sell stock at price '6' because after that no stocks are available as it is the last day :

                                profit = 0 - 0 = 0

        therefore, final profit = 4 + 0 + 4 + 0 = 8 

**You can also see diagram of how we are buying and selling :**
<img src="https://i.ibb.co/1sHnRkr/1688561988288.jpg" alt="emmet-example1" border="0">

**Detailed Explaination :**
```
    prices = {4, 8, 8, 7, 5, 6, 9, 6}   

1. Initialize variables:

    'holdStock' is set to the first stock price, which is 4.
    'nextStock' will be used to store the next stock price during iteration.
    'totalProfit' is initially set to 0.

2.  Iterating through the stock prices:

    2.a We start from the first stock and compare it with the next stock price.
    2.b Comparing 4 and 8, we see that the next stock price is greater, indicating an increasing trend. 
          We continue to the next iteration.
    
    Continuing the iterations:

    2.c Comparing 8 and 8, the next stock price is equal to the current price, so we continue to the 
          next iteration.
    2.d Comparing 8 and 7, the next stock price is less than the current price. This indicates the end 
          of an increasing stock.
    2.e We calculate the profit by subtracting the held stock price (holdStock) from the current stock price 
                            
                                            i.e  profit = 8 - 4 = 4
    
    2.f Add the calculated profit to the total profit: totalProfit += 4.
    
4. Updating the held stock price:

    4.a The current stock price (7) becomes the new held stock price (holdStock = 7).
          so, we buy this stock at same price :

                            therefore, profit = 7 - 7 = 0

5. Updating the held stock price:

    5.a The current stock price (5) becomes the new held stock price (holdStock = 5).

    Continuing the iterations:

    5.b Comparing 5 and 6, the next stock price is greater, indicating an increasing trend. 
          Continue to the next iteration.

    Continuing the iterations:

    5.c Comparing 6 and 9, the next stock price is greater. Continue to the next iteration.
    
    Continuing the iterations:

    5.d Comparing 9 and 6, the next stock price is less than the current price, indicating the end 
          of the final increasing subarray.
          Calculate the profit: 9 - 5 = 4. 
         Add the calculated profit to the total profit: totalProfit += 4.
    
    5.e Finally we will hold the last day stock price (holdStock = 6).

6. After that the loop will end.

7. Calculate the profit from selling the last stock by subtracting the held stock price (holdStock) from
    the last stock price (6 - 6 = 0).
    Add the calculated profit to the total profit: totalProfit += 0.

Final result:

        The total profit is 4 + 0 + 4 + 0  = 8.
```

The approach identifies the increasing stock prices and calculates the profit from each increasing stocks, considering the buy-sell transactions. The final result is the sum of profits obtained from each increasing stocks, represents the maximum possible profit that can be achieved by buying and selling stocks.




