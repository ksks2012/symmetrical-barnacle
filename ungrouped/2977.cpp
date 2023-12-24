#include "../include.h"


// votrubac
// Floyd-Warshall + DP
class Solution {
public:
    long long max_cost = 1000LL * 100LL * 1000000LL;
    unordered_map<int, unordered_set<string>> sz_tokens;
    unordered_map<string, unordered_map<string, long long>> m;
    long long dp[1001] = {};
    long long DFS(int i, string &s, string &t) {
        if (i >= s.size())
            return 0;
        long long res = max_cost + 1;
        if (dp[i] > 0)
            return dp[i] - 1;

        // select or not select
        if (s[i] == t[i])
            res = DFS(i + 1, s, t);
        for (auto &[sz, _] : sz_tokens) {
            if (i + sz <= s.size()) {
                auto ss = s.substr(i, sz), tt = t.substr(i, sz);
                if (m[ss].count(tt)) {
                    res = min(res, m[ss][tt] + DFS(i + sz, s, t));
                }
            }
        }
        dp[i] = res + 1;
        return res;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // Create graph
        for (int i = 0; i < original.size(); ++i) {
            int sz = original[i].size();
            sz_tokens[sz].insert(original[i]);
            sz_tokens[sz].insert(changed[i]);
            auto it = m[original[i]].find(changed[i]);
            if (it != end(m[original[i]]))
                it->second = min(it->second, (long long)cost[i]);
            else
                m[original[i]][changed[i]] = cost[i];
        }
        // Floyd-Warshall
        for (auto &[sz, tokens] : sz_tokens) {
            for (auto &k : tokens) {
                for (auto &i : tokens) {
                    for (auto &j : tokens) {
                        if (m[i].count(k) && m[k].count(j)) {
                            if (m[i].count(j) == 0)
                                m[i][j] = max_cost + 1;
                            m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                        }
                    }
                }
            }    
        }
        long long res = DFS(0, source, target);
        return res > max_cost ? -1 : res;
    }
};