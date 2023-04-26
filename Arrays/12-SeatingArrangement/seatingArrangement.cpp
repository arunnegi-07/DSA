// TC : O(N)   SC : O(1)

#include <iostream>
#include <vector>
using namespace std;

// This function checks if it's possible to get n consecutive empty seats in a row of m seats.
bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
    int i = 0;
    while(i < m)
    {    
        // if we are at first index then left = 0 as no value will be at left, else it will be previous value.  
        int left = (i == 0) ? 0 : seats[i-1];
        // if we are at last index then right = 0 as no value will be at right, else it will be next value.
        int right = (i == m-1) ? 0 : seats[i+1];

        // Check if the current seat is empty and the adjacent seats are also empty
        if (seats[i] == 0 && left + right== 0) {
            n--; // if we found a seat make number of people to be seated decrement by '1'
            i+=2; // skip the next seat since it's adjacent to the current empty seat
        } 
        else
            i++; // else move on to the next seat

        // if all people are seated return true
        if(!n) return 1;    
    }
    // if we didn't returned inside loop it means some people may not get the seat so return false
    return 0;
}

int main() {
    // Sample input 1
    vector<int> seats1 = {1,0,0,0,1,0,1};
    int n1 = 2;
    int m1 = seats1.size();
    bool possible1 = is_possible_to_get_seats(n1, m1, seats1);
    cout << "Sample input 1: " << possible1 << endl;

    // Sample input 2
    vector<int> seats2 = {1,0,0,0,1,0,1};
    int n2 = 3;
    int m2 = seats2.size();
    bool possible2 = is_possible_to_get_seats(n2, m2, seats2);
    cout << "Sample input 2: " << possible2 << endl;

    // Sample input 3
    vector<int> seats3 = {0,0,1,0,1,1,0,0,0,1};
    int n3 = 4;
    int m3 = seats3.size();
    bool possible3 = is_possible_to_get_seats(n3, m3, seats3);
    cout << "Sample input 3: " << possible3 << endl;

    return 0;
}
