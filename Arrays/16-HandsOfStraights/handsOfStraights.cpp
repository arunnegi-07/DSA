#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isStraightHand(int N, int groupSize, vector<int> &hand) {
    // Base case: If the total number of cards is not divisible by the group size, rearrangement is not possible
    if (N % groupSize != 0)
        return false;

    // Map to store the frequencies of each value
    map<int, int> freq;
    
    // Count the frequencies of each value in the hand
    for (int val : hand)
    {
        freq[val]++;
    }
    
    // Iterate over the frequency map
    for (auto it : freq)
    {
        // If the frequency of the current value is greater than 0
        if (it.second > 0)
        {
            // Check if there are enough consecutive values to form a group
            for (int i = 1; i < groupSize; i++)
            {
                // If the frequency of the consecutive value is less than the current value, rearrangement is not possible
                if (freq[it.first + i] < it.second)
                    return false;
                
                // Decrease the frequency of the consecutive value by the frequency of the current value
                freq[it.first + i] -= it.second;
            }
        }
    }
    
    // If all groups can be formed, return true
    return true;
}

int main() {
    // Sample inputs
    int N1 = 9;
    int groupSize1 = 3;
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};

    int N2 = 5;
    int groupSize2 = 2;
    vector<int> hand2 = {1, 2, 3, 4, 5};
    
    // Check if rearrangement is possible for sample inputs and display the results
    cout << "Sample Input 1: ";
    if (isStraightHand(N1, groupSize1, hand1))
        cout << "Rearrangement is possible." << endl;
    else
        cout << "Rearrangement is not possible." << endl;
    
    cout << "Sample Input 2: ";
    if (isStraightHand(N2, groupSize2, hand2))
        cout << "Rearrangement is possible." << endl;
    else
        cout << "Rearrangement is not possible." << endl;
    
    return 0;
}
