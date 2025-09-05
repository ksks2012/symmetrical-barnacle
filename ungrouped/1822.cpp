#include "include.h"

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for (int num : nums) {
            if (num == 0) return 0;
            product *= (num > 0) ? 1 : -1;
        }
        return (product > 0) ? 1 : -1;
    }
};