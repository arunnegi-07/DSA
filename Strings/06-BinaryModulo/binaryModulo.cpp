#include<bits/stdc++.h>
using namespace std;

int modulo(string s, int m) {
    int base = 1; // initialize the base value as 2^0 = 1
    int dec_value = 0; // initialize the decimal value as 0
    int len = s.length(); // find the length of the string
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '1') // if the current character is '1'
            dec_value += base; // add the corresponding power of 2 to the decimal value
            
        dec_value %= m; // take the modulo of the current decimal value with m
        base = (base * 2) % m; // calculate the next power of 2 modulo m
    }
    return dec_value % m; // return the final decimal value modulo m
}

int main() {
    // Sample input 1
    string s1 = "101101";
    int m1 = 5;
    int result1 = modulo(s1, m1);
    cout << "Input: s = " << s1 << ", m = " << m1 << endl;
    cout << "Output: " << result1 << endl;
    
    // Sample input 2
    string s2 = "110010101";
    int m2 = 7;
    int result2 = modulo(s2, m2);
    cout << "Input: s = " << s2 << ", m = " << m2 << endl;
    cout << "Output: " << result2 << endl;
    
    return 0;
}