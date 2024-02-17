#include "include.h"

// TLE
class Solution {
public:
    vector<int> A;
    int DFS(int left, int right, int target) {
        if(left >= right) {
            return 0;
        }
        int tmp = 0;
        if(left + 2 <= right && target == A[left] + A[left + 1]) {
            tmp = max(tmp, 1 + DFS(left + 2, right, target));
        }
        if(right - 2 >= left && target == A[right] + A[right - 1]) {
            tmp = max(tmp, 1 + DFS(left, right - 2, target));
        }
        if(target == A[left] + A[right]) {
            tmp = max(tmp, 1 + DFS(left + 1, right - 1, target));
        }

        return tmp;
    }

    int maxOperations(vector<int>& nums) {
        int ans = 0;
        A = nums;

        int left = 0;
        int right = nums.size() - 1;

        return 1 + max({DFS(left + 2, right, nums[0] + nums[1]), DFS(left, right - 2, nums[right] + nums[right - 1]), DFS(left + 1, right - 1, nums[0] + nums[right])});
    }
};

class Solution {
public:
    vector<int> A;
    int DFS(int left, int right, int target, vector<vector<int>> &dp) {
        if(left >= right) {
            return 0;
        }
        int &res = dp[left][right];
        if(res != -1) {
            return res;
        }
        int tmp = 0;
        if(left + 2 <= right && target == A[left] + A[left + 1]) {
            tmp = max(tmp, 1 + DFS(left + 2, right, target, dp));
        }
        if(right - 2 >= left && target == A[right] + A[right - 1]) {
            tmp = max(tmp, 1 + DFS(left, right - 2, target, dp));
        }
        if(target == A[left] + A[right]) {
            tmp = max(tmp, 1 + DFS(left + 1, right - 1, target, dp));
        }
        res = tmp;

        return tmp;
    }

    int maxOperations(vector<int>& nums) {
        int ans = 0;
        A = nums;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        int left = 0;
        int right = nums.size() - 1;    

        return 1 + max({DFS(left + 2, right, nums[0] + nums[1], dp), DFS(left, right - 2, nums[right] + nums[right - 1], dp), DFS(left + 1, right - 1, nums[0] + nums[right], dp)});
    }
};