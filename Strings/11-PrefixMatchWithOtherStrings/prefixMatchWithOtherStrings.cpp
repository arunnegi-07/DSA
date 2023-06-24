// Straight forward Approach
// TC : O(N*k)  SC : O(k)  --> to store prefix of length 'k'

#include <iostream>
#include <string>

int klengthpref(std::string arr[], int n, int k, std::string str) {
    // Base case: If the length of str is less than k, no match is possible.
    if (str.length() < k)
        return 0;

    // Slicing the prefix of length 'k' from str.
    std::string prefix = str.substr(0, k); // O(k)

    int ans = 0; 

    // Iterate through each string in arr[]
    for (int i = 0; i < n; i++) { // O(n)
        // If the length of the current string is less than k, move to the next string.
        if (arr[i].length() < k)
            continue;

        // Slicing the prefix of length 'k' from the current string.
        std::string curr = arr[i].substr(0, k); // O(k)

        // Compare the current prefix with the prefix from str.
        if (curr == prefix) // O(k)
            ans++;
    }

    return ans;
}

int main() {
    // Sample inputs
    int n = 6;
    std::string arr[] = {"abba", "abbb", "abbc", "abbd", "abaa", "abca"};
    std::string str = "abbg";
    int k = 3;

    // Function call
    int result = klengthpref(arr, n, k, str);
    std::cout << "Count: " << result << std::endl;

    return 0;
}

