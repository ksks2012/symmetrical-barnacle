#include "include.h"

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mx = ranges::max(nums);
        int all_lcm = 1;
        for (int x : nums) {
            all_lcm = lcm(all_lcm, x);
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int m = 1, l = 1, g = 0;
            for (int j = i; j < nums.size() && m <= all_lcm * mx; j++) {
                int x = nums[j];
                m *= x;
                l = lcm(l, x);
                g = gcd(g, x);
                if (m == l * g) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};