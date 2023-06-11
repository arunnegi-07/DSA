// Approach 1 : Brute Force
// TC : O(N*K)  SC : O(1)

#include <iostream>

// Function to update the array elements based on the given updates
void update(int a[], int n, int updates[], int k)
{
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            // Check if the current index plus 1 is greater than or equal to the update value
            if (i + 1 >= updates[j]) {
                // Increment the array element at index i by 1
                a[i] += 1;
            }
        }
    }
}

int main()
{
    int n, k;

    // Sample input 1
    n = 3;
    k = 4;
    int a1[] = {0, 0, 0};
    int updates1[] = {1, 1, 2, 3};

    // Call the update function
    update(a1, n, updates1, k);

    // Display the updated array
    std::cout << "Updated array 1:\n";
    for (int i = 0; i < n; i++) {
        std::cout << a1[i] << " ";
    }
    std::cout << std::endl;

    // Sample input 2
    n = 2;
    k = 3;
    int a2[] = {0, 0};
    int updates2[] = {1, 1, 1};

    // Call the update function
    update(a2, n, updates2, k);

    // Display the updated array
    std::cout << "Updated array 2:\n";
    for (int i = 0; i < n; i++) {
        std::cout << a2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

