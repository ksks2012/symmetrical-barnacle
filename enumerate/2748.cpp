#include "include.h"

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0, tmp[10]{};
        for (int x : nums) {
            for (int y = 1; y < 10; y++) {
                if (tmp[y] && gcd(y, x % 10) == 1) {
                    res += tmp[y];
                }
            }
            while (x >= 10) { 
                x /= 10;
            }
            tmp[x]++;
        }
        return res;
    }
};