#include "include.h"

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int res = 0;

        for(const auto& [num, cnt] : count) {
            if(cnt % k == 0) {
                res += num * cnt;
            }
        }

        return res;
    }
};