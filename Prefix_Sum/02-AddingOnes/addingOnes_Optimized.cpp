// Approach 1 : Optimized Approach --> Using Prefix Sum Method
// TC : O(N + K)  SC : O(1)

#include <iostream>

// Function to update the array elements based on the given updates using prefix sum approach
void update(int a[], int n, int updates[], int k)
{
    // Increment the array elements at the specified indices
    for (int i = 0; i < k; i++) {
        a[updates[i] - 1] += 1;
    }

    // Compute prefix sum to update the array elements
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
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

