#include "include.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> sum(n + 1, 0);
        long long tmp = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            sum[i + 1] = tmp;
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            if (auto it = m.find(nums[i] - k); it != end(m))
                ans = max(ans, sum[i + 1] - sum[it->second]);
            if (auto it = m.find(nums[i] + k); it != end(m))
                ans = max(ans, sum[i + 1] - sum[it->second]);
            // First find or smallest matching
            if (auto it = m.find(nums[i]); it == end(m) || sum[i] - sum[it->second] <= 0)
                m[nums[i]] = i;
        }
        if(ans == LLONG_MIN)
            return 0;

        return ans;
    }
};

// TLE
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> sum(n + 1, 0);
        long long tmp = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            sum[i + 1] = tmp;
            m[nums[i]] += 1;
        }
        
        long long ans = LLONG_MIN;
        for(int i = n - 1; i >= 0; i--) {
            int upper = nums[i] + k;
            int lower = nums[i] - k;
            if(m.find(upper) != m.end() || m.find(lower) != m.end()) {
                for(int j = 0; j < n; j++) {
                    if(nums[j] == upper) {
                        int tmp_i = i;
                        int tmp_j = j;
                        if(tmp_i < tmp_j) {
                            swap(tmp_i, tmp_j);
                        }
                        ans = max(ans, sum[tmp_i + 1] - sum[tmp_j]);
                    }

                    if(nums[j] == lower) {
                        int tmp_i = i;
                        int tmp_j = j;
                        if(tmp_i < tmp_j) {
                            swap(tmp_i, tmp_j);
                        }
                        ans = max(ans, sum[tmp_i + 1] - sum[tmp_j]);
                    }
                }
            }
        }
        if(ans == LLONG_MIN)
            return 0;

        return ans;
    }
};