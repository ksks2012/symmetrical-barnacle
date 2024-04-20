#include "../include.h"

// TLE
class Solution {
public:
    void dfs(vector<vector<int>>& g, int r, int c, int cl) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[r].size() || g[r][c] != cl) {
            return;
        }
        
        g[r][c] = -cl;
        
        dfs(g, r - 1, c, cl);
        dfs(g, r + 1, c, cl);
        dfs(g, r, c - 1, cl);
        dfs(g, r, c + 1, cl);
        
        if (r > 0 && r < g.size() - 1 && c > 0 && c < g[r].size() - 1 && 
            cl == abs(g[r - 1][c]) && cl == abs(g[r + 1][c]) && 
            cl == abs(g[r][c - 1]) && cl == abs(g[r][c + 1])) {
            
            g[r][c] = cl;
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0]);
        
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[i].size(); ++j) {
                grid[i][j] = grid[i][j] < 0 ? color : grid[i][j];
            }
        }
        
        return grid;
    }
};

class Solution {
public:
    // Define the pair_hash function before using it
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1,T2> &p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> bfs = {{r0, c0}};
        unordered_set<pair<int, int>, pair_hash> component, border;

        for (int k = 0; k < bfs.size(); ++k) {
            int r0 = bfs[k].first, c0 = bfs[k].second;
            vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            
            for (const auto& dir : dirs) {
                int i = dir[0], j = dir[1];
                int r = r0 + i, c = c0 + j;
                
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == grid[r0][c0]) {
                    if (component.find({r, c}) == component.end()) {
                        bfs.push_back({r, c});
                        component.insert({r, c});
                    }
                } else {
                    border.insert({r0, c0});
                }
            }
        }
        
        for (const auto& [x, y] : border) {
            grid[x][y] = color;
        }
        
        return grid;
    }
};
