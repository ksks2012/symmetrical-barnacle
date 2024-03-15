#include "include.h"

class Solution {
public:
    int minSwaps(string s) {
        int count_zero = count(s.begin(), s.end(), '0');
        int count_one = s.size() - count_zero;;
        int missing_zero = 0, missing_one = 0;

        if(abs(count_zero - count_one) > 1) {
            return -1;
        }
        for(int i = 0; i < s.size(); i+= 2) {
            missing_zero += s[i] != '0';
            missing_one += s[i] != '1';
        }

        if(count_zero == count_one) {
            return min(missing_zero, missing_one);
        }

        if(count_zero > count_one) {
            return missing_zero;
        }

        return missing_one;
    }
};