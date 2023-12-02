#include "include.h"

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
