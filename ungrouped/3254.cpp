#include "include.h"

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0;
        int consec_cnt = 1;
        
        for (int right = 0; right < nums.size(); right++) {
            if (right > 0 && nums[right - 1] + 1 == nums[right]) {
                consec_cnt++;
            }
            
            if (right - left + 1 > k) {
                if (nums[left] + 1 == nums[left + 1]) {
                    consec_cnt--;
                }
                left++;
            }
            
            if (right - left + 1 == k) {
                res.push_back(consec_cnt == k ? nums[right] : -1);
            }
        }
        
        return res;
    }
};