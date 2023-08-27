// Similar to approach 1, just different way of doing it
// TC : O(|S|)  SC : O(1)

#include <iostream>
using namespace std;

string reverseWord(string str)
{
    int start = 0, end = str.size()-1;
    
    // swap till start is less than end
    while(start < end){
        swap(str[start],str[end]);
        start++; end--;
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
