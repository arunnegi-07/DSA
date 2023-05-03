#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// TC : O(N*X)  SC : O(N)

bool wifiRange(int N, string S, int X){
    bool wifi[N] = {false}; // Initializing an array to keep track if room is getting wifi or not 
        
    for(int i=0;i<N;i++){
        if(S[i] == '1'){ // If there is a room with wifi at i-th position
            wifi[i] = true; // Mark i-th room as true in 'wifi' array as it conatins wifi
                
            for(int j = i+1;j <= i+X && j < N;j++) // Check which will get wifi on right side 'X' distance from that i-th room
                wifi[j] = true;
                
            for(int j = i-1;j >= 0 && j >= i-X;j--) // Check which will get wifi on left side 'X' distance from that i-th room
                wifi[j] = true;
            }
    }

    // traversing over 'wifi' array to check any room getting wifi or not
    for(auto i : wifi) 
        if(!i) return false; // If any room is there which do not get wifi, return false
           
    return true; // If all rooms are getting wifi, return true
}   

// Approach 2:
// TC : O(N)  SC : O(1)

bool wifiRange(int N, string S, int X){
    int distance = 0; // variable to keep track of consecutive rooms with no wifi
    bool ones_flag = false;  // To check if any room with wifi is previously present or not
    for(int i=0;i<N;i++){
        // If there is a room with wifi at i-th position
        if(S[i]=='1'){
            // if 'one_flag' was already 'true' and room between them is greater than 2*X, return false (or)
            //                        condition like this : 100000001
            // if 'one_flag' was 'false' and room to the left of it is greater than X, return flase 
            //                        condition like this : 0000001
            if((ones_flag && distance > 2*X) || (!ones_flag && distance > X)){
                return false;
            }
            // if both of the conditions above are not fulfilled means till now all rooms are getting wifi.
            // So, simply set the ones_flag = true and set distance back to zero as we are now proceeding to new part
            else{
                ones_flag = true;
                distance = 0;
            }
        }
        // if '0' is there simply increment the distance
        else
            distance++;
    }

    // Handling the case like this : 1000000 --> where at the end rooms with no wifi is/are available
    // In that case definitely 'distance' has some value in it and if it is greater than given 'X'
    // return false
    if(distance > X) return false;

    // If from nowhere 'false' is returned then it indicates all rooms has the wifi, return true 
    return true;
}  

int main(){
    // Sample Input 1:
    int N = 7; 
    string S = "1000101";
    int X = 1; 
    
    bool result = wifiRange(N, S, X);
    
    cout << "Can all Room get the wifi ? : "; result ? cout << "Yes" : cout << "No" << endl;
    
    // Sample Input 2:
    N = 7;
    S = "1000101";
    X = 2;
    
    result = wifiRange(N, S, X);
    
    cout << "Can all Room get the wifi ? : "; result ? cout << "Yes" : cout << "No" << endl;
    
    return 0;
}

