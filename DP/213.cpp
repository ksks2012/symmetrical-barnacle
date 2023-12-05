#include "include.h"

// TLE
class Solution {
public:
    int DFS(vector<int> &nums, int cur, bool last) {
        if(cur < 0) 
            return 0;
        if(last && cur == 0)
            return 0;

        int tmp = 0;
        if(last && cur == nums.size() - 1)
            tmp = max(DFS(nums, cur - 1, false), DFS(nums, cur - 2, true) + nums[cur]);
        else
            tmp = max(DFS(nums, cur - 1, last), DFS(nums, cur - 2, last) + nums[cur]);
        return tmp;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        return DFS(nums, n - 1, true);
    }
};

class Solution {
public:
    int DFS(vector<int> &nums, vector<int> &memo_l, vector<int> &memo_nl, int cur, bool last) {
        if(cur < 0) 
            return 0;
        if(last && memo_l[cur] != -1)
            return memo_l[cur];
        if(!last && memo_nl[cur] != -1)
            return memo_nl[cur];
        if(last && cur == 0)
            return 0;

        int tmp = 0;
        if(last && cur == nums.size() - 1)
            tmp = max(DFS(nums, memo_l, memo_nl, cur - 1, false), DFS(nums, memo_l, memo_nl, cur - 2, true) + nums[cur]);
        else
            tmp = max(DFS(nums, memo_l, memo_nl, cur - 1, last), DFS(nums, memo_l, memo_nl, cur - 2, last) + nums[cur]);
        
        if(last)
            memo_l[cur] = tmp;
        else
            memo_nl[cur] = tmp;
        
        return tmp;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> memo_l(n + 1, -1);
        vector<int> memo_nl(n + 1, -1);
        return DFS(nums, memo_l, memo_nl, n - 1, true);
    }
};