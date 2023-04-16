#include<bits/stdc++.h>
using namespace std;

long long solve(int N, vector<int> &A, vector<int> &B) {
    // Sorting both Arrays so that operations taken would be minimum
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
        
    // Variables to store sum of both vectors
    long long sumA = 0, sumB = 0;
        
    // Now, declaring vectors to store count of odd and even numbers in both Vectors
    vector<int> Aodds, Aevens, Bodds, Bevens;
        
    // Traversing over given Vectors to calculate Sum and count
    for(int i=0;i<N;i++){ 
        sumA += A[i];
        sumB += B[i];
            
        // if in 'A' value at index 'i' is odd push it in Aodds else in Aevens
        if(A[i] % 2) Aodds.push_back(A[i]);
        else Aevens.push_back(A[i]);
            
        // if in 'B' value at index 'i' is odd push it in Bodds else in Bevens
        if(B[i] % 2) Bodds.push_back(B[i]);
        else Bevens.push_back(B[i]);
    }
        
    // If sum of Both 'A' and 'B' is not equal (or)
    // No. of Odds (or) No. of Evens in both 'A' and 'B' are not equal return -1
    // else it is a confirmation that It is Possible to make 'A' and 'B' equal.
    if(sumA != sumB || Aodds.size() != Bodds.size()) return -1;
        
    // Now, Let us calculate, minimum no. of operations required to make 'A' and 'B' equal
        
    long long ans = 0; // variable to store the answer
        
    // First Let us check for odds 
    for(int i=0;i < Aodds.size();i++){
        // here we are doing divide by 2 because to change let's say 5 to 9 
        // we have to add '2' two times so no. of operations should be 2
        // but if we do abs(5-9) = 4 beacause doing like this means we are adding '1'
        // at a time, so to get correct operatios just divide it by '2'.
        ans += abs(Aodds[i] - Bodds[i])/2;
    }
        
    // Now, checking for evens 
    for(int i=0;i < Aevens.size();i++){
        // similarly dong same here
        ans += abs(Aevens[i] - Bevens[i])/2;
    }
        
    // Now, as questions says doing +2 and -2 for particular i and j 
    // will be considered as single operation so to get correct no. of operations
    // we have to further divide our calculated operations by '2' to get the
    // correct answer.
    return ans/2;
}

int main() {
    // Sample Input 1
    int N1 = 3;
    vector<int> A1 = {2, 5, 6};
    vector<int> B1 = {1, 2, 10};
    cout << solve(N1, A1, B1) << endl; // Expected Output: 2

    // Sample Input 2
    int N2 = 2;
    vector<int> A2 = {3, 3};
    vector<int> B2 = {9, 8};
    cout << solve(N2, A2, B2) << endl; // Expected Output: -1
}