#include "include.h"

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size(), left = 0;
        
        multiset<int> ms;
        vector<int> res;
        
        for(int right = 0; right < n; right++) {
            if(nums[right] < 0) 
                ms.insert(nums[right]);

            if(right - left + 1 == k) {
                if(ms.size() < x)
                    res.push_back(0);
                else 
                    res.push_back(*next(ms.begin(), x - 1));
                
                if(nums[left] < 0) 
                    ms.erase(ms.find(nums[left]));
                
                left++;
            }
        }
        
        return res;
    }
};