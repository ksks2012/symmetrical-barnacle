#include "include.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_prod(n, 0);
        vector<int> suf_prod(n, 0);

        int pre_cur = 1;
        int suf_cur = 1;
        for(int i = 0; i < n; i++) {
            pre_cur *= nums[i];
            pre_prod[i] = pre_cur;
            suf_cur *= nums[n - i - 1];
            suf_prod[n - i - 1] = suf_cur;
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans[i] = suf_prod[i + 1];
            } else if(i == n - 1) {
                ans[i] = pre_prod[i - 1];
            } else {
                ans[i] = pre_prod[i - 1] * suf_prod[i + 1];
            }
        }

        return ans;
    }
};