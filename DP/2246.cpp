#include "include.h"

class Solution {
public:
    int ans = 0;
    string s;
    vector<vector<int>> tree;
    int DFS(int x) {
        int x_len = 0;
        for(auto y : tree[x]) {
            int y_len = DFS(y) + 1;
            if(s[y] != s[x]) {
                ans = max(ans, x_len + y_len);
                x_len = max(x_len, y_len);
            }
        }
        return x_len;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        this->s = s;
        tree = vector<vector<int>> (n, vector<int>(0));
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
        DFS(0);
        return ans + 1;
    }
};