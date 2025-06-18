#include "../include.h"

class Solution {
public:
    int findNumbers(vector<int>& nums) {   
        int count = 0;
        
        for(int &num : nums) {
            if(num2digit(num) % 2 == 0)
               count++; 
        }
        
        return count;
    }
    
    int num2digit(int num) {     
        int digit = 0;
        int zero = 1; 
        while(zero <= num) {
            zero *= 10;    
            digit++;
        }
        return digit;
    }
    
};