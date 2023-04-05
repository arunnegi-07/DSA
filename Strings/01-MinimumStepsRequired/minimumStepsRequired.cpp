#include <iostream>
#include <string>
using namespace std;

int minSteps(string str) {
    // Initialize variables to keep track of number of 'a's and 'b's
    int n = str.size();
    int a = str[0] == 'a', b = str[0] == 'b';
    
    // Traversing the String
    for(int i=1;i<n;i++){
        a += str[i] == 'a' && str[i-1] == 'b';
        b += str[i] == 'b' && str[i-1] == 'a';
    }
    
    // Return minimum number of steps required to empty the string
    return 1 + min(a,b);
}

int main() {
    // Example 1: "abab", output should be 3
    string str1 = "abab";
    int output1 = minSteps(str1);
    cout << "Minimum number of steps to transform " << str1 << " is " << output1 << endl;
    
    // Example 2: "aba", output should be 2
    string str2 = "aba";
    int output2 = minSteps(str2);
    cout << "Minimum number of steps to transform " << str2 << " is " << output2 << endl;
    
    // Example 3: "aabaa", output should be 2
    string str3 = "aabaa";
    int output3 = minSteps(str3);
    cout << "Minimum number of steps to transform " << str3 << " is " << output3 << endl;
    
    return 0;
}
                                                                                                                                                                     