#include "include.h"

// prev : to store index of candle at or just before current index
// next : to store index of candle at or just after current index
// prefixSum : to store number of plates till the current index
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = s.length();
        vector<int> prev(n, n), next(n, n), prefixSum(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == '|')
                    prev[i] = i;
                else
                    prefixSum[i] = 1;
            } else {
                if (s[i] == '|') {
                    prev[i] = i;
                    prefixSum[i] = prefixSum[i - 1];
                } else {
                    prev[i] = prev[i - 1];
                    prefixSum[i] = 1 + prefixSum[i - 1];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|')
                next[i] = i;

            else if (i != n - 1 && s[i] != '|')
                next[i] = next[i + 1];
        }

        vector<int> ans;
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];

            int cur_next = next[l];
            int cur_prev = prev[r];

            if (cur_prev <= cur_next || cur_prev == n || cur_next == n) {
                ans.push_back(0);
            } else {
                ans.push_back(prefixSum[cur_prev] - prefixSum[cur_next]);
            }
        }
        return ans;
    }
};

// Binary Search Solution
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candle, res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '|')
                candle.push_back(i);
        }
            
        for (int q = 0; q < queries.size(); ++q) {
            int i = lower_bound(candle.begin(), candle.end(), queries[q][0]) - candle.begin();
            int j = upper_bound(candle.begin(), candle.end(), queries[q][1]) - candle.begin() - 1;
            res.push_back(i < j ? (candle[j] - candle[i]) - (j - i) : 0);
        }
        return res;
    }
};