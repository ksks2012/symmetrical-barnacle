#include "include.h"

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;

        for(auto n: nums) {
            if(n % 2 == 0)
                count++;
            if(count >= 2)
                return true;
        }

        return false;
    }
};