// Not actually a Bit Manipulation question, But we can say a variation of Kadanes Algorithm
// TC : O(N)  O(1)

#include <bits/stdc++.h>
using namespace std;

int maxOnes(int A[], int n)
{   
    // step 1 : Change all 1's to -1 and all 0's to 1 also count already present 1's
    int oneCount = 0;
    for(int i=0;i<n;i++){
        if(A[i] == 1){
            oneCount++;
            A[i] = -1; 
        }
        else{
            A[i] = 1;
        }
    }           
    
    if(oneCount == n)  // all ones
        return n;
    
    // Step 2: Now Simply apply Kadanes Algorithm
    int start = 0;
    int l=0,r=-1;
    int max = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum == 0) 
            start = i;
        
        sum += A[i];
        if(sum > max){
            max = sum;
            l = start;
            r = i;
        }
        
        if(sum < 0){
            sum = 0;
        }
    }

    // step 3 : Now calculate No. of 0's between l and r (make sure we have converted 0's to
    // '1' so count no. of 1's and return the Addition of them and previous ones which were present)
    // ALso make sure in that range 1 which were there are now flipped to 0's so subtract there count
    // from sum
    int flipOnes = 0;
    int flipZeroes = 0;
    for(int i=l;i<=r;i++){
        if(A[i] == 1)   // make sure in original 1's are zeroes
            flipOnes++;
        else
            flipZeroes++; // count of those 1's which are now become zero due to flip
    }
    
    return oneCount + flipOnes - flipZeroes;
}

int main() {
    // Sample input 1
    int input1[] = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int N1 = 9;
    int result1 = maxOnes(input1, N1);
    cout << "Maximum number of ones after flipping zeroes (Sample 1): " << result1 << endl;

    // Sample input 2
    int input2[] = {1, 0, 0, 1, 0, 1, 0, 1, 1};
    int N2 = 9;
    int result2 = maxOnes(input2, N2);
    cout << "Maximum number of ones after flipping one zeroes (Sample 2): " << result2 << endl;

    return 0;
}
