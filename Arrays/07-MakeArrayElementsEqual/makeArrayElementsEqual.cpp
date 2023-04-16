#include<iostream>
using namespace std;

// TC : O(1)  SC : O(1)

// Function to evaluate min operation required
long long int minOperations(int N) {
    // for odd N returning Sum of first N/2 even numbers
    // for even N returning Sum of first N/2 odd numbers
    return N % 2 ? (long long)N/2*(N/2+1) : (long long)(N/2)*(N/2);
}

int main(){
    // Sample input 1:
    int N1 = 5;
    cout << "Minimum No. of operation needed for N = " << N1 << ": " << minOperations(N1) << endl;

    // Sample input 2:
    int N2 = 6;
    cout << "Minimum No. of operation needed for N = " << N2 << ": " << minOperations(N2) << endl;
}