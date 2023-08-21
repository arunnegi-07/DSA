// Approach 1 : Naive Approach  --> Simple straight forward liinear search
// TC : O(N)  SC : O(1)

#include <iostream>
#include <vector>  

// Function to find the lower bound of 'x' in a sorted vector 'arr'
int lowerBound(std::vector<int> arr, int n, int x) {
    int lowerBoundIndex = -1;  // Initialize with an invalid index

    for (int i = 0; i < n; ++i) {
        if (arr[i] >= x) {
            lowerBoundIndex = i;
            break;  // Found the lower bound, exit the loop
        }
    }
    return lowerBoundIndex;
}

int main() {
    // Sample input 1
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    int n1 = arr1.size();
    int x1 = 6;

    int result1 = lowerBound(arr1, n1, x1);

    if (result1 != -1) {
        std::cout << "Lower bound of " << x1 << " in sample input 1 is at index " << result1 << ". Element: " << arr1[result1] << std::endl;
    } else {
        std::cout << x1 << " is greater than all elements in sample input 1." << std::endl;
    }

    // Sample input 2
    std::vector<int> arr2 = {2, 4, 6, 8, 10};
    int n2 = arr2.size();
    int x2 = 5;

    int result2 = lowerBound(arr2, n2, x2);

    if (result2 != -1) {
        std::cout << "Lower bound of " << x2 << " in sample input 2 is at index " << result2 << ". Element: " << arr2[result2] << std::endl;
    } else {
        std::cout << x2 << " is greater than all elements in sample input 2." << std::endl;
    }

    return 0;
}
