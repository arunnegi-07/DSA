/* Approach 1 : BruteForce Method
    TC : O(N*N)  SC : O(1)

    This Problem is the variation of famous problem '2 sum' or 'find pair sum', only difference is that there 
    we have some 'target' given while here we want the sum to be '1'.
    Another difference is here we have given fractions.

    Idea Behind the BruteForce Solution:
        Idea is a simple Mathematics, if we have given two fractions :
                    a / b and c / d , then both fractions sum equal to '1', when
                                        a * d + b * c == b * d    
                                                                                                                                                                                                                                                                                                                                        */
#include <iostream>
using namespace std;

int countFractions(int n, int numerator[], int denominator[]) {
    int count = 0;  // Initialize a count to keep track of pairs of fractions that sum to 1.

    // Loop through each pair of fractions in the array.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Extract the numerator and denominator of the first fraction.
            int a = numerator[i], b = denominator[i];
            
            // Extract the numerator and denominator of the second fraction.
            int c = numerator[j], d = denominator[j];

            // Check if the sum of the fractions is equal to 1 (a/b + c/d = 1).
            if (a * d + b * c == b * d) {
                count++;  // Increment the count if the fractions sum to 1.
            }
        }
    }

    return count;  // Return the count of pairs of fractions that sum to 1.
}

int main() {
    // Sample input 1
    int n1 = 4;
    int numerator1[] = {1, 2, 2, 8};
    int denominator1[] = {2, 4, 6, 12};
    int result1 = countFractions(n1, numerator1, denominator1);
    cout << "Sample Input 1: " << result1 << " pairs of fractions sum to 1." << endl;

    // Sample input 2
    int n2 = 5;
    int numerator2[] = {3, 1, 12, 81, 2};
    int denominator2[] = {9, 10, 18, 90, 5};
    int result2 = countFractions(n2, numerator2, denominator2);
    cout << "Sample Input 2: " << result2 << " pairs of fractions sum to 1." << endl;

    return 0;
}
