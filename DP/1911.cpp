#include "include.h"

// DFS: TLE
class Solution {
public:
    vector<int> nums;
    int n;
    long long DFS(int i, int j) {
        if(i < 0)
            return 0;
        
        if(j % 2 == 0) {
            return max(DFS(i - 1, j + 1) + nums[i], DFS(i - 1, j));
        }
        return max(DFS(i - 1, j + 1) - nums[i], DFS(i - 1, j));
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        return DFS(n - 1, 0);
    }
};

// DFS: TLE
class Solution {
public:
    vector<int> nums;
    int n;
    long long DFS(int i, int odd) {
        if(i < 0) {
            if(odd)
                return 0;
            else
                return nums[0];
        }
            
        
        if(odd) {
            return max(DFS(i - 1, 0) - nums[i], DFS(i - 1, 1));
        }
        return max(DFS(i - 1, 1) + nums[i], DFS(i - 1, 0));
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        return DFS(n - 1, 0);
    }
};


// DFS with memory: TLE
class Solution {
public:
    vector<int> nums;
    int n;
    long long DFS(int i, int j, vector<vector<int>> &memo) {
        if(i < 0)
            return 0;
        
        int &res = memo[i][j];
        if(res != -1)
            return res;

        if(j % 2 == 0) {
            return res = max(DFS(i - 1, j + 1, memo) + nums[i], DFS(i - 1, j, memo));
        }
        return res = max(DFS(i - 1, j + 1, memo) - nums[i], DFS(i - 1, j, memo));
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(n - 1, 0, memo);
    }
};

class Solution {
public:
    vector<int> nums;
    int n;
    long long DFS(int i, int odd, vector<vector<int>> &memo) {
        if(i < 0) {
            if(odd)
                return 0;
            else
                return nums[0];
        }

        int &res = memo[i][odd];
        if(res != -1)
            return res;    
        
        if(odd) {
            return res = max(DFS(i - 1, 0, memo) - nums[i], DFS(i - 1, 1, memo));
        }
        return res = max(DFS(i - 1, 1, memo) + nums[i], DFS(i - 1, 0, memo));
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        return DFS(n - 1, 0, memo);
    }
};

// Iteration
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = 0;

        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

// Space Optimization
class Solution {
public:
    long long maxAlternatingSum(vector<int>& A) {
        long long odd = 0, even = 0;
        for (int& a: A)
            even = max(even, odd + a),
            odd = even - a;
        return even;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long preEven = 0, preOdd = 0;
        for(auto& n : nums){
            preEven = max(preEven, preOdd + n);
            preOdd = max(preOdd, preEven - n);
        }
        return max(preOdd, preEven);
    }
};