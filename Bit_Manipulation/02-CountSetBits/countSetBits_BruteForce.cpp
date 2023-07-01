/* Approach 1 : This approach is staight forward and simple we are just keep on dividing the number by 2 and 
                         if in any step remainder is '1' then we will increase the count simply which indicates in it's binary
                         representation that bit is high. 
                                                                                                                                                                                                                                                                            
        TC : O(logN)  SC : O(1)                                                                                
                                                                                                                                                                                                                                                                                    */
#include <iostream>

int setBits(int N) {
    int count = 0;
    while (N > 0) {
        if (N % 2 == 1) {  // Check if the rightmost bit is set
            count++;
        }
        N /= 2;  // Divide N by 2 to move to the next bit
    }
    return count;
}

int main() {
    // Sample inputs
    int num1 = 6;
    int num2 = 8;
    
    // Count set bits for num1
    int count1 = setBits(num1);
    std::cout << "Number of set bits in " << num1 << ": " << count1 << std::endl;
    
    // Count set bits for num2
    int count2 = setBits(num2);
    std::cout << "Number of set bits in " << num2 << ": " << count2 << std::endl;
    
    return 0;
}
