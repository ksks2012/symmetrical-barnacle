#include "include.h"

// DFS: TLE
class Solution {
public:
    vector<int> nums;
    int DFS(int i) {
        int res = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] >= nums[j]) {
                res = max(res, DFS(j));
            }
        }
        return res + 1;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans;

        this->nums = obstacles;

        for(int i = 0; i < n; i++) {
            ans.push_back(DFS(i));
        }

        return ans;
    }
};

// DFS with memory: TLE
class Solution {
public:
    vector<int> nums;
    int DFS(int i, vector<int> &memo) {
        int &tmp = memo[i];
        if(tmp != -1)
            return tmp;
        int res = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] >= nums[j]) {
                res = max(res, DFS(j, memo));
            }
        }
        return tmp = res + 1;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans;

        this->nums = obstacles;
        vector<int> memo(n + 1, -1);
        for(int i = 0; i < n; i++) {
            ans.push_back(DFS(i, memo));
        }

        return ans;
    }
};

// 2D-array: TLE
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] >= nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return dp;
    }
};

// O(nlogn)
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        auto end = nums.begin();

        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin(), end, nums[i]);
            ans[i] = (it - nums.begin() + 1);
            *it = nums[i];
            if(it == end)
                ++end;
        }
        return ans;
    }
};