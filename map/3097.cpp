#include "include.h"

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cnt[30] = {}, cur = 0, res = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            for (int bit = 0; bit < 30; ++bit)
                if ((1 << bit) & nums[i])
                    if (++cnt[bit] == 1)
                        cur += (1 << bit);
            while (cur >= k && j <= i) {
                res = min(res, i - j + 1);
                for (int bit = 0; bit < 30; ++bit)
                    if ((1 << bit) & nums[j])
                        if (--cnt[bit] == 0)
                            cur -= (1 << bit);
                ++j;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};