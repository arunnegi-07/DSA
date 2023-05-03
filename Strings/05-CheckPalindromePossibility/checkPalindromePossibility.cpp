#include<bits/stdc++.h>
using namespace std;

bool makePalindrome(int n,vector<string> &arr){
    // To store each strings
    unordered_map<string, int> mp;

    // Storing count corresponding to each string in 'arr'
    for(auto str:arr){
        mp[str] ++;
    }

    // Again Iterating over 'arr' to check if it is possible to make palindrome 
    for(auto str:arr){
        // storing count of incoming string in some variable 'x'
        int x = mp[str];
        // storing that string in some variable 's' for further opeartions
        string s = str;
        // reversing the string we got from the 'arr'
        reverse(s.begin(),s.end());
        // if that string is equal to it's own reverse means it is a paindrome 
        // and it will definitely going to contribute in making palindrome so continue
        if(str == s) continue;
        // but if above condition is not satisfied then store count of that reversed string from 'mp'
        // if count of original string and reversed string are not same it means we cannot make palindrome
        // because there is always some string for which reverse is not present
        int y = mp[s];
        if(x != y)  return false;  // so return false in that case
    }
    // if false is not returned from inside means it is possible to make plaindrome out of given set of strings.
    return true;
}

int main() {

    // Test case 1
    vector<string> arr1 = {"abc", "def", "ghi", "ihg", "fed", "cba"};
    int n1 = 6;
    if (makePalindrome(n1, arr1)) {
        cout << "It is possible to make a palindrome" << endl;
    } else {
        cout << "It is not possible to make a palindrome" << endl;
    }

    // Test case 2
    vector<string> arr2 = {"abc", "def", "ghi", "ijk"};
    int n2 = 4;
    if (makePalindrome(n2, arr2)) {
        cout << "It is possible to make a palindrome" << endl;
    } else {
        cout << "It is not possible to make a palindrome" << endl;
    }

    return 0;
}
