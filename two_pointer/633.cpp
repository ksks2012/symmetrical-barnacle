#include "../include.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        long int left = 0;
        long int right = (int)sqrt(c);
        
        while (left <= right) {
            if(left * left + right * right == c)
                return true;
            if(left * left + right * right < c)
                left++;
            if(left * left + right * right > c)
                right--;
        }
        
        return false;
    }
};