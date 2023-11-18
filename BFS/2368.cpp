#include "include.h"

class Solution {
public:
    int max_n;
    int count;
    void DFS(vector<vector<int>> &m, int cur, vector<int> &visited) {
        if(m[cur].size() == 0 || visited[cur] == 1)
            return;

        count++;
        visited[cur] = 1;
        for(auto &i : m[cur]) {
            if(visited[i] == 0) {
                DFS(m, i, visited);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        max_n = n;
        count = 0;

        vector<vector<int>> m(n, vector<int>());
        for(auto &e: edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        for(auto &r: restricted) {
            visited[r] = 1;
        }

        DFS(m, 0, visited);
        return count;
    }
};