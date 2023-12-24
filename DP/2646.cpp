#include "include.h"

// endlesscheng
class Solution {
public:
    vector<vector<int>> tree;
    vector<vector<int>> trips;
    vector<int> price;
    vector<int> count;

    pair<int, int> DFS(int cur, int parent) {
        // cur not changed
        int not_halve = price[cur] * count[cur]; // x not changed
        // half of cur
        int halve = not_halve / 2;
        for (int y: tree[cur]) {
            if (y != parent) {
                // sum of y not change/half
                auto [nh, h] = DFS(y, cur);
                // find min when cur not change, y cannot change and can be half
                not_halve += min(nh, h);
                // half of cur and y cannot change
                halve += nh;
            }
        }
        return {not_halve, halve};
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        tree = vector<vector<int>>(n);
        this->trips = trips;
        this->price = price;
        // Create graph
        for(auto e: edges) {
            int x = e[0];
            int y = e[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        count = vector<int>(n);
        auto [nh, h] = DFS(0, -1);
        return min(nh, h);
    }
};