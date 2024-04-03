#include "include.h"

// lee
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, maxi = 1;
        for (int n : nums) {
            int bits = 0;
            while (n > 0) {
                res += n & 1;
                bits++;
                n >>= 1;
            }
            maxi = max(maxi, bits);
        }
        return res + maxi - 1;
    }
};