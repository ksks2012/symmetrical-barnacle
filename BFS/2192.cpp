#include "../include.h"

class Solution {
public:
    void DFS(vector<vector<int>> &tmp, vector<vector<int>> &ans, int cur, int start) {
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

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans (n);
        vector<vector<int>> tmp (n, vector<int>{}); //store the ancestors
        for (auto e : edges)
            tmp[e[1]].push_back(e[0]);
        for (int i = 0; i < n; i++) {
            vector<bool> visit (n, 0); //visited ancestor in this bfs search path
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                if (!visit[q.front()]) {
                    visit[q.front()] = 1;
                    for (auto n : tmp[q.front()]) //find grand parents
                        if (!visit[n])
                            q.push(n);
                }
                q.pop();
            }
            visit[i] = 0; //excluding descendant itself
            for (int anc = 0; anc < n; anc++)
                if (visit[anc])
                    ans[i].push_back(anc);
        }
        return ans;
    }
};
