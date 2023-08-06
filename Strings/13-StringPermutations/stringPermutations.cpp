#include <bits/stdc++.h>
using namespace std;

// Function to generate all permutations of a given string 'str' using backtracking
void generatePermutations(string str, int start, int end, vector<string> &ans) {
    // Base case: When the start index reaches the end index, we have a complete permutation.
    // So, we add it to the 'ans' vector and return from the recursion.
    if (start == end) {
        ans.push_back(str);
        return;
    }

    // Loop through all the characters from 'start' to 'end'
    for (int i = start; i <= end; i++) {
        // Swapping characters at indices 'start' and 'i'.
        // This effectively creates a new permutation by fixing one character (at 'start')
        // and permuting the remaining characters (from 'start+1' to 'end') recursively.
        swap(str[start], str[i]);

        // Recursively generate permutations for the remaining characters.
        // Here, we move to the next character in the string and repeat the process.
        generatePermutations(str, start + 1, end, ans);

        // Backtrack by restoring the original string to explore other possibilities.
        // After the recursive call returns, we need to restore the original order of characters
        // so that we can try permuting other characters at 'start'.
        swap(str[start], str[i]);
    }
}    

// Function to find all permutations of the given string 'S' and return them in lexicographical order.
vector<string> permutation(string S) {
    int n = S.length();
    vector<string> ans;

    // Call the recursive function to generate all permutations.
    generatePermutations(S, 0, n - 1, ans);

    // Sort the permutations in lexicographical order.
    // After generating all permutations, we sort them to ensure they are in lexicographical order.
    // Lexicographical order means the permutations will be arranged in dictionary order.
    // For example, if the input is "cba", the output will be ["abc", "acb", "bac", "bca", "cab", "cba"].
    sort(ans.begin(), ans.end());

    // Return the vector containing all permutations.
    return ans;
}


int main() {
    // Sample Input 1: Permutations of "abc"
    string input1 = "abc";
    vector<string> result1 = permutation(input1);

    cout << "Permutations of " << input1 << ":" << endl;
    for (const string &perm : result1) {
        cout << perm << endl;
    }
    cout << endl;

    // Sample Input 2: Permutations of "xyz"
    string input2 = "xyz";
    vector<string> result2 = permutation(input2);

    cout << "Permutations of " << input2 << ":" << endl;
    for (const string &perm : result2) {
        cout << perm << endl;
    }

    return 0;
}
