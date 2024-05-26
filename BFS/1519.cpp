#include "include.h"

class Solution {
public:
    void DFS(int i, string &labels, vector<vector<int>>& tmp, int count[], vector<int> &res) {
        if (res[i] == 0) {
            res[i] = 1;
            for (auto j : tmp[i]) {
                int count_tmp[26] = {};
                DFS(j, labels, tmp, count_tmp, res);
                for (auto k = 0; k < 26; ++k)
                    count[k] += count_tmp[k];
            }
            // count label
            res[i] = ++count[labels[i] - 'a'];
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        int count[26] = {};
        vector<vector<int>> tmp(n);
        // build graph
        for (auto &e : edges) {
            tmp[e[0]].push_back(e[1]);
            tmp[e[1]].push_back(e[0]);
        }
        DFS(0, labels, tmp, count, ans);
        return ans;
    }
};
