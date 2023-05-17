// TC : O(StringLength)  SC : O(1)

#include <iostream>
#include <string>

using namespace std;

int isPossible(int n, int m, string s) {
    int x = 0, y = 0; // initial position of the train
    int minx = 0, maxx = 0, miny = 0, maxy = 0; // variables to track minimum and maximum values of x and y

    for (auto ch : s) {
        if (ch == 'L') {
            y -= 1; // Move left, decrement column index
            miny = min(y, miny); // Update the minimum y value encountered
        }
        if (ch == 'R') {
            y += 1; // Move right, increment column index
            maxy = max(y, maxy); // Update the maximum y value encountered
        }
        if (ch == 'D') {
            x -= 1; // Move up, decrement row index
            minx = min(x, minx); // Update the minimum x value encountered
        }
        if (ch == 'U') {
            x += 1; // Move down, increment row index
            maxx = max(x, maxx); // Update the maximum x value encountered
        }
    }

    // Check if there is a cell from which the train can start and remain inside the grid
    if ((n - maxx) - (1 - minx) >= 0 && (m - maxy) - (1 - miny) >= 0) {
        return 1; // There is a cell from which the train can start and remain inside the grid
    }
    return 0; // No such cell exists
}

int main() {
    int n, m;
    string s;

    // Sample input 1
    n = 1;
    m = 1;
    s = "R";
    cout << isPossible(n, m, s) << endl; // Output: 0

    // Sample input 2
    n = 2;
    m = 3;
    s = "LLRU";
    cout << isPossible(n, m, s) << endl; // Output: 1

    return 0;
}
