/*   TC : O(N)  SC : O(1)  --> because task are only given as alphabets, and only '26' letters are there
                                             therefore at max space complexity of O(26) will be taken which is nearly equal to O(1)
                                                                                                                                                                                                                                                                                    */
#include <bits/stdc++.h>
using namespace std;

int leastInterval(int N, int K, vector<char> &tasks) {
    unordered_map<char, int> freq; // Initialized a map to store frequency of each task

    // Storing frequencies of each task
    for (auto val : tasks) {
        freq[val]++;
    }

    int maxi = 0; // To store the maximum occurred task
    int maxCount = 0; // To store the count of tasks that occurred maximum times

    // Calculating the maximum frequency (maxi)
    for (auto val : freq) {
        maxi = max(maxi, val.second);
    }

    // Calculating the count of tasks with maximum frequency (maxCount)
    for (auto val : freq) {
        if (maxi == val.second) {
            maxCount++;
        }
    }

    int time = maxi + (maxi - 1) * K + (maxCount - 1); // Calculating the total time required

    return max(N, time); // Returning the maximum of N and time (to handle cases where N is smaller than the required time)
}

int main() {
    // Sample input 1
    int N1 = 6;
    int K1 = 2;
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Minimum units of time for sample input 1: " << leastInterval(N1, K1, tasks1) << endl;

    // Sample input 2
    int N2 = 12;
    int K2 = 2;
    vector<char> tasks2 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << "Minimum units of time for sample input 2: " << leastInterval(N2, K2, tasks2) << endl;

    return 0;
}
