/* Approach 1 : Naive Approach
    TC : O(N)  SC : O(digits in result)  --> Taking space to return the result

    Even though the time complexity of the solution is O(N), still this is not the Efficient approach to find
    factorial because if you run this program for values after 'N = 20' then even the datatype 'long long'
    will overflow and you never get the correct result.
    And the constraint in problem is 1 <= N <= 1000
    So, as program is failing for very small value N = 21, then for a large value like N = 1000 you definitely
    know it will not work.
                                                                                                                                                                                                                                                                                                                                */

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate factorial and extract its digits
vector<int> factorial(int N) {
    // Calculate the factorial
    long long factorial_result = 1;  // Initialize the result to 1
    for (int i = 1; i <= N; ++i) {
        factorial_result *= i;  // Multiply the current value with the result
    }
    
    // Convert the factorial result to a vector of its digits
    vector<int> digits;  // Create a vector to store digits
    while (factorial_result > 0) {
        digits.insert(digits.begin(), factorial_result % 10);  // Insert digit at the beginning
        factorial_result /= 10;  // Remove the last digit
    }
    
    return digits;  // Return the vector of digits
}

int main() {
    int N = 5;
    vector<int> result = factorial(N);
    cout << "Factorial of " << N << " is: ";
    for (int digit : result) {
        cout << digit;  // Output: 120
    }
    cout << endl;
    
    N = 10;
    result = factorial(N);
    cout << "Factorial of " << N << " is: ";
    for (int digit : result) {
        cout << digit;  // Output: 3628800
    }
    cout << endl;
    
    return 0;
}
