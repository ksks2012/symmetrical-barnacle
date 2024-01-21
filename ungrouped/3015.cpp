#include "include.h"

#define INF 102
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for(int i = 1; i < n; i++) {
            graph[i][i] = 0;
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }
        if(x != y) {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        graph[n][n] = 0;

            for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                if (graph[i][k] != INF) {
                    for (int j = 0; j <= n; j++) {
                        if (graph[k][j] != INF) {
                            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(graph[i][j] != INF && graph[i][j] != 0) {
                    ans[graph[i][j] - 1]++;
                }
            }
        }

        return ans;
    }
};