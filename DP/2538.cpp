#include "include.h"

#define PAIR_LL pair<long long, long long>
class Solution {
public:
    long long ans = 0;
    vector<int> price;
    vector<vector<int>> tree;

    PAIR_LL DFS(int cur, int parent) {
        long long p = price[cur];
        long long max_s1 = p; // with node
        long long max_s2 = 0;

        for(int y: tree[cur]) {
            if(y != parent) {
                auto [s1, s2] = DFS(y, cur);
                // Maximum leaf path sum in front + current non-leaf path sum
                // Maximum non-leaf path sum + current leaf path sum 
                ans = max(ans, max(max_s1 + s2, max_s2 + s1));

                // x is not leaf
                max_s1 = max(max_s1, s1 + p);
                max_s2 = max(max_s2, s2 + p);
            }
        }
        return {max_s1, max_s2};
    }

    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
        tree = vector<vector<int>>(n);
        // Create graph
        for(auto e: edges) {
            int x = e[0];
            int y = e[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        this->price = price;

        DFS(0, -1);

        return ans;
    }
};