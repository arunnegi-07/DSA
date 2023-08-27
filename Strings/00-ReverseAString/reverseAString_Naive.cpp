// TC : O(|S|)  SC : O(1)

#include <iostream>
using namespace std;

string reverseWord(string str) {
    int n = str.length();

    // Traverse half of the string and swap characters
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    return str;
}

int main() {
    string s = "Geeks";
    string reversed = reverseWord(s);
    cout << reversed << endl;

    s = "for";
    reversed = reverseWord(s);
    cout << reversed << endl;

    return 0;
}
