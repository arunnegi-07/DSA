// TC : O(|S|)  SC : O(|S|)

#include <iostream>
#include <string>
using namespace std;

string reverseEqn(string S) {
    string result = "";
    int i = S.length() - 1;

    while (i >= 0) {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
            // If the character is an operator, append it to the result
            result += S[i];
            i--;
        } else {
            // Extract the number
            int num_start = i;
            while (i >= 0 && isdigit(S[i])) {
                i--;
            }
            int num_end = i + 1;

            // Append the number to the result
            result += S.substr(num_end, num_start - num_end + 1);
        }
    }
    return result;
}

int main() {
    string equation1 = "20-3+5*2";
    string equation2 = "5+2*56-2/4";

    cout << "Original Equation 1: " << equation1 << endl;
    cout << "Reversed Equation 1: " << reverseEqn(equation1) << endl;

    cout << "Original Equation 2: " << equation2 << endl;
    cout << "Reversed Equation 2: " << reverseEqn(equation2) << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string reverseEqn(string S) {
    string result = "";
    int i = S.length() - 1;

    while (i >= 0) {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
            // If the character is an operator, append it to the result
            result += S[i];
            i--;
        } else {
            // Extract the number
            int num_start = i;
            while (i >= 0 && isdigit(S[i])) {
                i--;
            }
            int num_end = i + 1;

            // Append the number to the result
            result += S.substr(num_end, num_start - num_end + 1);
        }
    }
    return result;
}

int main() {
    string equation1 = "20-3+5*2";
    string equation2 = "5+2*56-2/4";

    cout << "Original Equation 1: " << equation1 << endl;
    cout << "Reversed Equation 1: " << reverseEqn(equation1) << endl;

    cout << "Original Equation 2: " << equation2 << endl;
    cout << "Reversed Equation 2: " << reverseEqn(equation2) << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string reverseEqn(string S) {
    string result = "";
    int i = S.length() - 1;

    while (i >= 0) {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
            // If the character is an operator, append it to the result
            result += S[i];
            i--;
        } else {
            // Extract the number
            int num_start = i;
            while (i >= 0 && isdigit(S[i])) {
                i--;
            }
            int num_end = i + 1;

            // Append the number to the result
            result += S.substr(num_end, num_start - num_end + 1);
        }
    }
    return result;
}

int main() {
    string equation1 = "20-3+5*2";
    string equation2 = "5+2*56-2/4";

    cout << "Original Equation 1: " << equation1 << endl;
    cout << "Reversed Equation 1: " << reverseEqn(equation1) << endl;

    cout << "Original Equation 2: " << equation2 << endl;
    cout << "Reversed Equation 2: " << reverseEqn(equation2) << endl;

    return 0;
}
