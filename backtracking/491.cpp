#include "include.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        backtracking(0, nums, vector<int>(), ans);
        return vector(ans.begin(), ans.end());
    }

    void backtracking(int start, vector<int> nums, vector<int> cur, set<vector<int>>& ans) {
        int m = cur.size();
        int n = nums.size();
        if(m != 0 && m > 1) {
            ans.insert(cur);
        }
        
        if(start > n) {
            ans.insert(cur);
            return;
        }
            
        for(int i = start; i < n; i++) {
            // ignore repeated numbers
            if (m == 0 || m > 0 && cur[m - 1] <= nums[i]) {
                cur.push_back(nums[i]);
                backtracking(i + 1, nums, cur, ans);
                cur.pop_back();
            }
        }

    }
};