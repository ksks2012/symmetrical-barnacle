#include "include.h"

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_sum(n, 0);
        vector<int> suf_sum(n, 0);
        vector<int> ans(n, 0);
        
        pre_sum[0] = nums[0];
        suf_sum[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i];
            suf_sum[n - i - 1] = suf_sum[n - i] + nums[n - i - 1];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = ((nums[i] * i) - pre_sum[i]) + (suf_sum[i] - (nums[i] * (n - i - 1)));
            cout << i << " " << ans[i] << endl;
        }

        return ans;
    }
};