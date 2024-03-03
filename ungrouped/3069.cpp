#include "include.h"

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return nums;
        
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < n; i++) {
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        vector<int> ans;
        ans.insert(ans.end(), arr1.begin(), arr1.end());
        ans.insert(ans.end(), arr2.begin(), arr2.end());

        return ans;
    }
};