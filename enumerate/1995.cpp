#include "include.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        
        unordered_map<int, int> count;
        count[nums[len - 1] - nums[len - 2]] = 1;
        
        for (int i = len - 3; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                res += count[nums[j] + nums[i]];
            }
            
            for (int x = len - 1; x > i; x--) {
                count[nums[x] - nums[i]]++;
            }
        }
        
        return res;
    }
};