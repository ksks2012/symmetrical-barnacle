#include "include.h"

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int res = x, sum = 0;
        int tmp = 100;
        while(tmp > 0) {
            sum += x / tmp;
            x = x % tmp;
            tmp /= 10;
        }
        if(res % sum == 0)
            return sum;
        
        return -1;
    }
};