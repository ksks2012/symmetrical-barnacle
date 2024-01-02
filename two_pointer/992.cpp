#include "../include.h"

// lee
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int K) {
        return atMostK(nums, K) - atMostK(nums, K - 1);
    }

    int atMostK(vector<int>& nums, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < nums.size(); ++j) {
            if (!count[nums[j]]++) 
                K--;
            while (K < 0) {
                if (!--count[nums[i]]) {
                    K++;
                }
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};