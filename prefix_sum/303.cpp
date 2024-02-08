#include "include.h"

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int tmp = 0;
        sum.push_back(tmp);
        for(int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            sum.push_back(tmp);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */