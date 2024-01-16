#include "include.h"

// lee
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int last[30] = {}, n = nums.size();
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if (nums[i] & (1 << j))
                    last[j] = i;
                res[i] = max(res[i], last[j] - i + 1);
            }
        }
        return res;
    }
};

// WA
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            int maxi = nums[i];
            int tmp = 0;
            int cur = nums[i];
            int left = i;
            for(int j = i + 1; j < n; j++) {
                cur |= nums[i];
                while(cur < maxi) {
                    cur ^= nums[left];
                }
                if(cur >= maxi) {
                    tmp = max(tmp, j - i + 1);
                }
            }
            ans[i] = tmp;
        }

        return ans;   
    }
};