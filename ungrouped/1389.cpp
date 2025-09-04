#include "include.h"

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        
        res.push_back(nums[0]);
        
        for(int i = 1; i < index.size(); i++) {
            
            res.insert(res.begin() + index[i], nums[i]);
            
        }
        return res;
    }
};