#include "../include.h"

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        int m = nums.size();
        
        int max_num = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                int tmp = nums[i] ^ nums[j];
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    max_num = max(max_num, tmp);
            }
        }

        return max_num;        
    }
};