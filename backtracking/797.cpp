#include "include.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        backtracking(graph, ans, 0, vector<int>(1, 0));
        return ans;
    }

    void backtracking(vector<vector<int>>& graph, vector<vector<int>> &ans, int cur_idx, vector<int> cur) {
        if(graph[cur_idx].size() == 0 && cur_idx == graph.size() - 1) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < graph[cur_idx].size(); i++) {
            cur.push_back(graph[cur_idx][i]);
            backtracking(graph, ans, graph[cur_idx][i], cur);
            cur.pop_back();
        }
    }
};