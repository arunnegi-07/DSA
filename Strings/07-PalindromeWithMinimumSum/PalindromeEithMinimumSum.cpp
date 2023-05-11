#include<bits/stdc++.h>
using namespace std;

// Function to check if it is possible to obtain a palindrome from the given string
bool possible(string s) {
    int low = 0, high = s.length() - 1;
    while (low < high) {
        if (s[low] != '?' && s[high] != '?' && s[low] != s[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

// Function to solve the problem
int solve(string st) {
    int n = st.length(), i = 0, low = 0, high = n - 1;
    char s[n+1];
    strcpy(s, st.c_str());

    // Replace the '?' characters in the string with the corresponding characters from the other end of the string
    while (low < high) {
        if (s[low] == '?') {
            s[low] = s[high];
        }
        else if (s[high] == '?') {
            s[high] = s[low];
        }
        low++;
        high--;
    }

    // Find the first non-'?' character in the string
    while (i < n && s[i] == '?') {
        i++;
    }
    // If all characters are '?' return 0
    if (i == n) {
        return 0;
    }

    // Calculate the minimum sum required to make the string a palindrome
    int ans = 0;
    char prev = s[i];
    for (int x = i; x < n; x++) {
        if (s[x] == '?') {
            s[x] = prev;
        }
        ans += abs(s[x] - prev);
        prev = s[x];
    }

    return ans;
}

// Main function that calls the other functions and returns the result
int minimumSum(string s) {
    if (!possible(s)) { // Check if it is possible to obtain a palindrome from the given string
        return -1;
    }
    else {
        return solve(s); // Solve the problem and return the minimum sum required to make the string a palindrome
    }
}


int main(){
    // Example input 1
    string s1 = "a??a";
    int ans1 = minimumSum(s1);
    cout << "Minimum sum for " << s1 << " is " << ans1 << endl;

    // Example input 2
    string s2 = "a?b?c";
    int ans2 = minimumSum(s2);
    cout << "Minimum sum for " << s2 << " is " << ans2 << endl;

    return 0;
}
