#include "../include.h"

class Solution {
public:
    void DFS(vector<vector<int>> &tmp, vector<vector<int>> &ans, int cur, int start) {
        cout << cur << " " << start << endl;
        for(auto i : tmp[cur]) {
            if(ans[i].empty() || ans[i].back() != start) {
                ans[i].push_back(start);
                DFS(tmp, ans, i, start);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tmp(n);
        for(int i = 0; i < edges.size(); i++) {
            tmp[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            DFS(tmp, ans, i, i);
        }
        return ans;
    }
};