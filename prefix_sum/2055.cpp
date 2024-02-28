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

            int i = next[l];
            int j = prev[r];

            if (j <= i || j == n || i == n) {
                ans.push_back(0);
            } else {
                ans.push_back(prefixSum[j] - prefixSum[i]);
            }
        }
        return ans;
    }
};