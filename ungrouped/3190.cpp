#include "include.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            int tmp = nums[i] % 3;
            if(tmp != 0) {
                res++;
            }
        }

        return res;
    }
};