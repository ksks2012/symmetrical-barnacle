#include "include.h"

class UnionFind {
private:
    vector<int> fa;

public:
    int cc; // Number of connected components

    UnionFind(int n) : fa(n), cc(n) {
        ranges::iota(fa, 0);
    }

    int find(int x) {
        // Path compression optimization
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) {
            return;
        }
        fa[x] = y;
        cc--;
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; i++) {
            sets[i] = unordered_set(properties[i].begin(), properties[i].end());
        }

        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int cnt = 0;
                for (int x : sets[j]) {
                    if (sets[i].contains(x)) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.cc;
    }
};