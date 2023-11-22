#include "include.h"

// Error for checking
class Solution {
public:
    vector<int> way{-1, 0, 1, 0, -1};
    int m;
    int n;

    queue<pair<int, int>> q;

    int DFS(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
            return 1;
        
        if(grid[x][y] == 2) {
            q.push(pair<int, int>(x, y));
        }

        grid[x][y] = 0;
        int res = 1;

        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            res &= DFS(grid, tmp_x, tmp_y);
        }
        return res;
    }

    int check_isolate(vector<vector<int>> grid) {
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                }
                if(grid[i][j] == 1 || grid[i][j] == 2) {
                    ans += DFS(grid, i, j);
                }
                if(ans > 1) {
                    return ans;
                }
            }
        }
        return ans;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        int iso = check_isolate(grid);
        if(iso == 1) {
            if(q.size() == 0)
                return -1;
            while (!q.empty()) {
                int q_size = q.size();
                for(int i = 0; i < q_size; ++i) {
                    pair<int, int> top = q.front(); 
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = top.first + way[k];
                        int y = top.second + way[k + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) 
                            continue;
                        if(grid[x][y] == 1) {
                            grid[x][y] = 2;
                            q.push(pair<int, int>(x, y));
                        }  
                    }
                }
                ++count;
            }
        } else if (iso == 0) {
            return 0;
        }

        return count - 1;
    }
};

class Solution {
public:
    vector<int> way{-1, 0, 1, 0, -1};
    int m;
    int n;

    queue<pair<int, int>> q;

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        int good = 0;
        int bad = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                    bad++;
                } else if(grid[i][j] == 1) {
                    good++;
                }
            }
        }
    
        if(good == 0) {
            return 0;
        }
        if(bad == 0) {
            return -1;
        }

        while (!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i) {
                pair<int, int> top = q.front(); 
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = top.first + way[k];
                    int y = top.second + way[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) 
                        continue;
                    if(grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push(pair<int, int>(x, y));
                    }  
                }
            }
            ++count;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return count - 1;
    }
};