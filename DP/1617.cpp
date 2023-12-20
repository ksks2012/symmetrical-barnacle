#include "include.h"

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> ans, in_set, visited;
    int n;
    int tmp;
    
    // length of the tree
    int DFS(int x) {
        visited[x] = true;
        int max_len = 0;
        for (int y : tree[x])
            if (!visited[y] && in_set[y]) {
                int ml = DFS(y) + 1;
                tmp = max(tmp, max_len + ml);
                max_len = max(max_len, ml);
            }
        return max_len;
    }

    void helper(int i) {
        if (i == n) {
            for (int v = 0; v < n; ++v)
                if (in_set[v]) {
                    fill(visited.begin(), visited.end(), 0);
                    tmp = 0;
                    DFS(v);
                    break;
                }
            if (tmp && visited == in_set)
                ++ans[tmp - 1];
            return;
        }

        // not chose city i
        helper(i + 1);

        // chose city i
        in_set[i] = true;
        helper(i + 1);
        in_set[i] = false; // restore
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        this->n = n;
        tree = vector<vector<int>>(n);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        ans = vector<int>(n - 1);
        in_set = vector<int>(n);
        visited = vector<int>(n);
        tmp = 0;

        helper(0);
        
        return ans;
    }
};