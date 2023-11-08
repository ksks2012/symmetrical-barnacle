#include "../include.h"

class Solution {
public:
	vector<int> way = {0, 1, 0, -1, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
        int n = grid[0].size();
        int area = 0;

        stack<pair<int, int>> route;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    route.push(pair<int, int>(i, j));
                    int tmp_area = 1;
                    while(!route.empty()) {
                        pair<int, int> top = route.top();
                        route.pop();
                        for(int k = 0; k < 4; k++) {
                            int tmp_i = top.first + way[k];
                            int tmp_j = top.second + way[k + 1];
                            if(tmp_i < 0 || tmp_i >= m || tmp_j < 0 || tmp_j >= n) {
                                continue;
                            }
                            if(grid[tmp_i][tmp_j] == 1) {
                                route.push(pair<int, int>(tmp_i, tmp_j));
                                grid[tmp_i][tmp_j] = 0;
                                tmp_area++;
                            }
                        }
                    }
                    area = max(area, tmp_area);
                }
            }
        }

		return area;
	}
};
