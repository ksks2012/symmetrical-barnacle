#include "../include.h"

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int target = arr[j] - arr[i];
                if(target < arr[i] && index.find(target) != index.end()) {
                    dp[i][j] = dp[index[target]][i] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res == 2 ? 0 : res;      
    }
};