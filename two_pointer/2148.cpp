#include "include.h"

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // count 1
        int n = nums.size();
        int one_count = 0;
        for(auto num : nums) {
            if(num == 1)
                one_count++;
        }

        // find longest string with 1
        int ans = n;
        int cur = 0;

        for(int i = 0, j = 0; i < n; i++) {
            while(j - i < one_count) {
                cur += nums[j++ % n];
            }
            ans = min(ans, one_count - cur);        
            cur -= nums[i]; 
        }

        return ans;
    }
};