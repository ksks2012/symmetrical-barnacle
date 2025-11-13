#include "include.h"

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        int left = 0;
        for(int i = 0; i < n; i++){
            if(left <= nums[i]){
                res++;
                left = nums[i];
            }
        }

        return res;
    }
};