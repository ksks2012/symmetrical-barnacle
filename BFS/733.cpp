#include "../include.h"

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int m;
    int n;
    void fill(vector<vector<int>>& image, vector<vector<int>>& visited, long long target, int x, int y, int color) {
        if(x < 0 || x >= m || y < 0 || y >= n) {
            return;
        }

        if (image[x][y] == target && !visited[x][y]) {
            image[x][y] = color;
            visited[x][y] = 1;
            for(int k = 0; k < 4; k++) {
                fill(image, visited, target, x + way[k], y + way[k + 1], color);
            }
        }     
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        if(image[sr][sc] != color)
            fill(image, visited, image[sr][sc], sr, sc, color);
        return image;
    }
};