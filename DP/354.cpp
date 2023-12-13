#include "include.h"

// DFS: TLE
class Solution {
public:
    vector<vector<int>> e;
    int n;
    int DFS(int cur, int prev) {
        if(cur == n)
            return 0;

        if(prev == -1 || e[prev][0] < e[cur][0] && e[prev][1] < e[cur][1]) {
            return max(DFS(cur + 1, prev), 1 + DFS(cur + 1, cur));
        }
        return DFS(cur + 1, prev);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        n = envelopes.size();
        this->e = envelopes;
        sort(this->e.begin(), this->e.end());
        return DFS(0, -1);
    }
};

// DFS with memo
class Solution {
public:
    vector<vector<int>> e;
    int n;
    int DFS(int cur, int prev, vector<vector<int>>& memo) {
        if(cur == n)
            return 0;

        int &res = memo[cur + 1][prev + 1];
        if(res != -1)
            return res;

        if(prev == -1 || e[prev][0] < e[cur][0] && e[prev][1] < e[cur][1]) {
            return res = max(DFS(cur + 1, prev, memo), 1 + DFS(cur + 1, cur, memo));
        }
        return res = DFS(cur + 1, prev, memo);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        n = envelopes.size();
        this->e = envelopes;
        sort(this->e.begin(), this->e.end());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(0, -1, memo);
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (e[j][1] < e[i][1]) {
                    dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n][n];
    }
};

// 1-D array
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// O(nlogn)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> nums;
        for(int i = 0; i < n; i++) {
            nums.push_back(envelopes[i][1]);
        }
        auto end = nums.begin();
        for (int num : nums) {
            auto it = lower_bound(nums.begin(), end, num);
            *it = num;
            if (it == end) 
                ++end;
        }
        return end - nums.begin();
    }
};