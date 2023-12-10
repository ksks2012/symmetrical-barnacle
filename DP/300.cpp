#include "../include.h"

// TLE
class Solution {
public:
    vector<int> nums;
    int n;
    int DFS(int i) {
        int res = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                res = max(res, DFS(j));
            }
        }
        return res + 1;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, DFS(i));
        }
        
        return ans;
    }
};

// DFS with memory
class Solution {
public:
    vector<int> nums;
    int n;
    int DFS(int i, vector<int> &memo) {
        int &tmp = memo[i];
        if(tmp != -1)
            return tmp;
        int res = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                res = max(res, DFS(j, memo));
            }
        }
        return tmp = res + 1;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        int ans = 0;
        vector<int> memo(n + 1, -1);
        for(int i = 0; i < n; i++) {
            ans = max(ans, DFS(i, memo));
        }
        
        return ans;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Time Optimization O(N * logN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> tmp;

        for(auto num : nums) {
            auto it = lower_bound(tmp.begin(), tmp.end(), num);
            if(it == tmp.end()) {
                tmp.push_back(num);
            } else {
                *it = num;
            }
        }
        return tmp.size();
    }
};