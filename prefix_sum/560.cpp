#include "include.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            sum[i] = nums[i - 1] += sum[i - 1];
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j <= nums.size(); ++j) {
                if(sum[j] - sum[i] == k) {
                    ans++;
                }
            }    
        }

        return ans;
    }
};

// with map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> m;
        int sum = 0;
        m[0] = 1;

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int target = sum - k;
            if(m.find(target) != m.end()){
                ans += m[target];
            }
            m[sum]++;
        }

        return ans;
    }
};