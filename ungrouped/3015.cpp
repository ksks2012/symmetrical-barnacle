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

        int i = 0, j = 0, k = 0;
        for (k = 0; k < n + 1; k++) {
            // Pick all vertices as source one by one
            for (i = 0; i < n + 1; i++) {
                // Pick all vertices as destination for the
                // above picked source
                for (j = 0; j < n + 1; j++) {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of
                    // graph[i][j]
                    if (graph[i][j] > (graph[i][k] + graph[k][j])
                        && (graph[k][j] != INF
                            && graph[i][k] != INF))
                        graph[i][j] = graph[i][k] + graph[k][j];
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