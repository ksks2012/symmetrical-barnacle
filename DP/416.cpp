#include "include.h"

// TLE
class Solution {
public:
    bool DFS(vector<int>& nums, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return true;
            else
                return false;
        }
        if(target < nums[cur_idx])
            return DFS(nums, target, cur_idx - 1);
        return DFS(nums, target, cur_idx - 1) || DFS(nums, target - nums[cur_idx], cur_idx - 1);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // find sum of all array elements
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (sum % 2 != 0) 
            return false;

        int target = sum / 2;
        return DFS(nums, target, n - 1);
    }
};

// MLE
class Solution {
public:
    bool DFS(vector<int>& nums, int target, int cur_idx, vector<vector<int>> memo) {
        if(cur_idx < 0) {
            if(target == 0)
                return true;
            else
                return false;
        }
        int &res = memo[target][cur_idx];
        if(res != -1)
            return res;
        if(target < nums[cur_idx])
            return res = DFS(nums, target, cur_idx - 1, memo);
        return res = DFS(nums, target, cur_idx - 1, memo) || DFS(nums, target - nums[cur_idx], cur_idx - 1, memo);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // find sum of all array elements
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (sum % 2 != 0) 
            return false;

        int target = sum / 2;
        vector<vector<int>> memo(target + 1, vector<int>(n + 1, -1));
        return DFS(nums, target, n - 1, memo);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        // find sum of all array elements
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (sum % 2 != 0) 
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) 
            return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<vector<optional<bool>>> memo(n + 1, vector<optional<bool>>(subSetSum + 1, nullopt));
        return DFS(nums, n - 1, subSetSum, memo);
    }

    bool DFS(vector<int> &nums, int n, int subSetSum, vector<vector<optional<bool>>> &memo) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        // check if subSetSum for given n is already computed and stored in memo
        if (memo[n][subSetSum] != nullopt) {
            return (memo[n][subSetSum] == true);
        }
        bool result = DFS(nums, n - 1, subSetSum - nums[n - 1], memo) || DFS(nums, n - 1, subSetSum, memo);
        memo[n][subSetSum] = result;
        return result;
    }
};
