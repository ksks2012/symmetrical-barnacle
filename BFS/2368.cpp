#include "include.h"

class Solution {
public:
    int max_n;
    int count;
    void DFS(unordered_map<int,vector<int>> &m, int cur, unordered_set<int> &visited) {
        if(visited.count(cur))
            return;

        count++;
        visited.insert(cur);
        for(auto &i : m[cur]) {
            if(!visited.count(i)) {
                DFS(m, i, visited);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        max_n = n;
        count = 0;

        unordered_map<int,vector<int>> m;
        for(auto &e: edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }

        unordered_set<int>visited;
        for(auto &r: restricted) {
            visited.insert(r);
        }

        DFS(m, 0, visited);
        return count;
    }
};