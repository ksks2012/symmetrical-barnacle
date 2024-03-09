#include "../include.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int start = -1;
        int first_neg = -2;
        int neg = 0;
        for(int i = 0; i < n; i++) {
            // reset
            if(nums[i] == 0) {
                neg = 0;
                start = i;
                first_neg = -2;
            } else {
                // number of negative number in window
                if(nums[i] < 0)
                    neg++;
                // init first_neg for counting negative number
                if(neg == 1 && first_neg == -2)
                    first_neg = i;
                // result of windw is positive number
                if(neg % 2 == 0)
                    maxi = max(maxi, i -start);
                else
                    maxi = max(maxi, i - first_neg);
            }
        }
        return maxi;
    }
};