// TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(int N, vector<int> &bills) {
    // Initialize counts for available 5-dollar and 10-dollar bills
    int countFive = 0, countTen = 0;

    // Iterate over each bill
    for(int i = 0; i < N; i++){
        if(bills[i] == 5){
            // If the bill is 5 dollars, increment countFive
            countFive++;
        }
        // If the bill is 10 dollars
        else if(bills[i] == 10){
            // Check if there is a 5-dollar bill available to give as change
            if(countFive > 0){
                countTen++; // Increment countTen as we are getting 10 dollar
                countFive--; // Decrement countFive as change is given
            }
            else{
                // Cannot provide change, return false
                return false;
            }
        }
        // If the bill is 20 dollars
        else{
            // Give change in the form of one 10-dollar bill and one 5-dollar bil if available
            if(countFive > 0 && countTen > 0){
                countFive--;  // Decrement countFive as change is given
                countTen--;  // Decrement countTen as change is given
            }
            // If there are at least three 5-dollar bills, give change by decrementing countFive by 3
            else if(countFive > 2){
                countFive -= 3;   // Decrement countFive by 3 as three bill of 5-dollar is given
            }
            else{
                // Cannot provide change, return false
                return false;
            }
        }
    }

    // All customers received correct change
    return true;
}

int main() {
    // Sample inputs
    int N1 = 5;
    vector<int> bills1 = {5, 5, 5, 10, 20};

    int N2 = 4;
    vector<int> bills2 = {10, 10, 20, 5};

    // Call the lemonadeChange function for each sample input
    bool result1 = lemonadeChange(N1, bills1);
    bool result2 = lemonadeChange(N2, bills2);

    // Print the results
    cout << "Result 1: " << (result1 ? "true" : "false") << endl;
    cout << "Result 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
