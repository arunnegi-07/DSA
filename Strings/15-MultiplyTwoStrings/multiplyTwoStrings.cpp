// TC : O(S1*S2)  SC : O(S1+S2) 

#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string s1, string s2) {
    // Step 1: Determine if the result will be negative based on the signs of s1 and s2.
    bool isNegative = (s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-');
    
    // Remove the negative signs if present.
    s1 = s1[0] == '-' ? s1.substr(1) : s1;
    s2 = s2[0] == '-' ? s2.substr(1) : s2;
    
    // Step 2: Find the lengths of the input strings.
    int len1 = s1.length();
    int len2 = s2.length();
    
    // Step 3: Initialize a result vector to store intermediate multiplication results.
    vector<int> result(len1 + len2, 0);
    
    // Step 4: Perform multiplication using nested loops.
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            // Multiply digits at the current positions and add to the corresponding position in the result vector.
            int product = (s1[i] - '0') * (s2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10; // Store the ones digit.
            result[i + j] += sum / 10;    // Carry over the tens digit.
        }
    }
    
    // Step 5: Convert the result vector to a string.
    string resultStr = "";
    for (int num : result) {
        resultStr += to_string(num);
    }
    
    // Step 6: Remove leading zeros from the result string.
    size_t start = resultStr.find_first_not_of('0');
    if (start == string::npos) {
        return "0";
    }
    resultStr = resultStr.substr(start);
    
    // Step 7: Add a negative sign if the result is negative and not zero.
    if (isNegative && resultStr != "0") {
        resultStr = "-" + resultStr;
    }
    
    // Step 8: Return the final result as a string.
    return resultStr;
}

int main() {
    string s1 = "0033";
    string s2 = "2";
    cout << multiplyStrings(s1, s2) << endl;  // Output: "66"

    s1 = "-11";
    s2 = "23";
    cout << multiplyStrings(s1, s2) << endl;  // Output: "253"

    return 0;
}
