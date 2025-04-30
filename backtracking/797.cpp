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

// lee
class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur) {
        path.push_back(cur);
        if (cur == graph.size() - 1)
            res.push_back(path);
        else for (auto it: graph[cur])
            DFS(graph, res, path, it);
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(graph, res, path, 0);
        return res;
    }
};

   