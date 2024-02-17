#include "include.h"

// TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if((sum[j + 1] - sum[i]) % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};

// lee
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) {
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};