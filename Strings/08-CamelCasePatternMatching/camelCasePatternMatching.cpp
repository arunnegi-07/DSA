#include <iostream>
#include <vector>
using namespace std;

// to check if particular alphabet in given word is Capital
bool isCapital(char alphabet) {
    if (alphabet >= 65 && alphabet <= 90)
        return true;
    else
        return false;
}

vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
    int ptr = 0;
    vector<string> ans;

    for (auto words : Dictionary) {
        for (int i = 0; i < words.size(); i++) {
            if (isCapital(words[i]) && Pattern[ptr] == words[i]) {
                ptr++;
            }
            // In case if word is capital and the current Pattern letter is not matched,
            // it means the current word is not what we want, so break
            else if (isCapital(words[i])) {
                break;
            }
        }

        // If after coming out of the loop, the value of ptr becomes equal to the actual size of the pattern,
        // it means we have to include it in our answer
        if (ptr == Pattern.size())
            ans.push_back(words);

        // Setting ptr back to '0' for checking the next word
        ptr = 0;
    }

    // If no word is matched with our pattern, add "-1" to ans
    if (ans.size() == 0)
        ans.push_back("-1");

    // Finally returning the answer
    return ans;
}

int main() {
    // Sample Input 1
    int N1 = 3;
    vector<string> Dictionary1 = {"WelcomeGeek", "WelcomeToGeeksForGeeks", "GeeksForGeeks"};
    string Pattern1 = "WTG";

    cout << "Sample Input 1:" << endl;
    cout << "Dictionary: WelcomeGeek, WelcomeToGeeksForGeeks, GeeksForGeeks" << endl;
    cout << "Pattern: " << Pattern1 << endl;
    cout << "Output: ";
    vector<string> result1 = CamelCase(N1, Dictionary1, Pattern1);
    for (string word : result1) {
        cout << word << " ";
    }
    cout << endl << endl;

    // Sample Input 2
    int N2 = 8;
    vector<string> Dictionary2 = {"Hi", "Hello", "HelloWorld", "HiTech", "HiGeek", "HiTechWorld", "HiTechCity", "HiTechLab"};
    string Pattern2 = "HA";

    cout << "Sample Input 2:" << endl;
    cout << "Dictionary: Hi, Hello, HelloWorld, HiTech, HiGeek, HiTechWorld, HiTechCity, HiTechLab" << endl;
    cout << "Pattern: " << Pattern2 << endl;
    cout << "Output: ";
    vector<string> result2 = CamelCase(N2, Dictionary2, Pattern2);
    for (string word : result2) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}