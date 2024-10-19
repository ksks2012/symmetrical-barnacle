#include "include.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Hash map to store the first occurrence of each remainder
        unordered_map<int, int> mp;
        // Initialize with remainder 0 at index -1 to handle the case of subarray starting at index 0
        mp[0] = -1;
        
        int prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int target = prefix_sum % k;
            
            if (target < 0) {
                target += k;
            }
            
            if (mp.find(target) != mp.end()) {
                // If the same remainder has been seen before, check the subarray length
                if (i - mp[target] > 1) {
                    return true;
                }
            } else {
                // Store the index of the first occurrence of this remainder
                mp[target] = i;
            }
        }
        
        return false;
    }
};
