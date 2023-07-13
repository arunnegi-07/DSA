// TC : O(N)  SC : O(N)

#include <iostream>
#include <unordered_map>
using namespace std;

bool isFrequencyUnique(int n, int arr[]) {
    // Step 1: Count the frequency of each element
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Check for duplicate frequencies
    unordered_map<int, int> occurrence; // to store occurences of each element in order to check if it's unique or not
    for (auto val : freq) {
        // If the frequency is already present in the 'occurrence' map, it is not unique
        if (occurrence.find(val.second) != occurrence.end()) {
            return false;
        }
        // if not already present 'occurence' map then add it
        occurrence[val.second]++;
    }
    return true;
}

int main() {
    // Sample input 1
    int arr1[] = {1, 1, 2, 5, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Sample Input 1: [1, 1, 2, 5, 5]\n";
    std::cout << "Is frequency unique? " << (isFrequencyUnique(n1, arr1) ? "Yes" : "No") << "\n\n";

    // Sample input 2
    int arr2[] = {2, 2, 5, 10, 1, 2, 10, 5, 10, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Sample Input 2: [2, 2, 5, 10, 1, 2, 10, 5, 10, 2]\n";
    std::cout << "Is frequency unique? " << (isFrequencyUnique(n2, arr2) ? "Yes" : "No") << "\n";

    return 0;
}
