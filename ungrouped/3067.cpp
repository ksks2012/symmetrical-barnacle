#include "include.h"

// votrubac
class Solution {
public:
    int dfs(int i, int p, int dist, int ss, vector<vector<pair<int, int>>> &nw) {
        int cnt = dist > 0 && dist % ss == 0, pairs = 0;
        for (auto [j, w] : nw[i])
            if (j != p) {
                int cnt_j = dfs(j, i, dist + w, ss, nw);
                pairs += cnt * cnt_j;
                cnt += cnt_j;
            }
        return i == p ? pairs : cnt;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> nw(n);
        vector<int> res(n);
        for (const auto &e : edges) {
            nw[e[0]].push_back({e[1], e[2]});
            nw[e[1]].push_back({e[0], e[2]});
        }
        for (int i = 0; i < n; ++i)
            res[i] = dfs(i, i, 0, signalSpeed, nw);
        return res;
    }
};