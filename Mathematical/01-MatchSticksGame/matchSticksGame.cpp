// Approach : Mathematical 
// TC : O(1)   SC : O(1)

#include <iostream>
using namespace std;

int matchGame(long long N) {
    // If N is divisible by 5, it is impossible for player A to win
    if(N % 5 == 0)
        return -1;
    else
        // The number of matchsticks A should pick is equal to the remainder of N divided by 5
        return N % 5;
}

int main() {
    // Sample inputs
    long long N1 = 48;
    long long N2 = 15;

    // Calculate the number of matchsticks A should pick for the given inputs
    int result1 = matchGame(N1);
    int result2 = matchGame(N2);

    // Print the results
    cout << "For N = " << N1 << ", A should pick " << result1 << " matchsticks." << endl;
    cout << "For N = " << N2 << ", A should pick " << result2 << " matchsticks." << endl;

    return 0;
}
