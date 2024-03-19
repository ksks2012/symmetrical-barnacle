#include "include.h"

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> dp{{0, -1}};
        int n = nums.size();
        int sum = 0, right = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            // sum - target
            if (dp.count(sum - target)) {
                int left = dp[sum - target];
                if (right <= left) {
                    ++ans;
                    // follow minimum right index
                    // update right
                    right = i;
                }
            }
            dp[sum] = i;
        }
        return ans;
    }
};

// Using set
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int res = 0;
        int sum = 0;
        unordered_set<int> s;
        s.insert(0);
        for (auto i : nums) {
            sum += i;
            if (s.find(sum - target) != s.end()) {
                s.clear();
                sum = 0;
                res++;
            }
            s.insert(sum);
        }
        return res;
    }
};