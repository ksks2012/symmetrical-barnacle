#include "../include.h"

// DFS
class Solution {
public:
    int find_x(int x, int y, int z, int len) {
        return DFS(x - 1, y, z, len + 1, 0);
    }
    
    int find_y(int x, int y, int z, int len) {
        return DFS(x, y - 1, z, len + 1, 1);
    }

    int find_z(int x, int y, int z, int len) {
        return DFS(x, y, z - 1, len + 1, 2);
    }

    int DFS(int x, int y, int z, int len, int pre) {
        // cout << x << ", " << y << ", " << z << ", " << len << ", " << pre << endl;
        if(x < 0 || y < 0 || z < 0)
            return len - 1;
        
        int res = 0;
        if(pre == -1) {
            res = max({res, find_x(x, y, z, len), find_y(x, y, z, len), find_z(x, y, z, len)});
        } else if(pre == 0) {
            // x -> y
            res = max(res, find_y(x, y, z, len));   
        } else if(pre == 1 || pre == 2) {
            // y -> x or y -> z
            // z -> x or z -> z
            res = max({res, find_x(x, y, z, len), find_z(x, y, z, len)});   
        }

        return res;
    }

    int longestString(int x, int y, int z) {
        return DFS(x, y, z, 0, -1) * 2;
    }
};

// DFS with memory
class Solution {
    int dp[51][51][51][5];
public:
    int find_x(int x, int y, int z, int len) {
        return DFS(x - 1, y, z, len + 1, 0);
    }
    
    int find_y(int x, int y, int z, int len) {
        return DFS(x, y - 1, z, len + 1, 1);
    }

    int find_z(int x, int y, int z, int len) {
        return DFS(x, y, z - 1, len + 1, 2);
    }

    int DFS(int x, int y, int z, int len, int pre) {
        // cout << x << ", " << y << ", " << z << ", " << len << ", " << pre << endl;
        if(x < 0 || y < 0 || z < 0)
            return len - 1;
        
        int &res = dp[x][y][z][pre + 1];
        if(res != -1)
            return res;
        
        if(pre == -1) {
            res = max({res, find_x(x, y, z, len), find_y(x, y, z, len), find_z(x, y, z, len)});
        } else if(pre == 0) {
            // x -> y
            res = max(res, find_y(x, y, z, len));   
        } else if(pre == 1 || pre == 2) {
            // y -> x or y -> z
            // z -> x or z -> z
            res = max({res, find_x(x, y, z, len), find_z(x, y, z, len)});   
        }

        return res;
    }

    int longestString(int x, int y, int z) {
        memset(dp,-1,sizeof(dp));
        return DFS(x, y, z, 0, -1) * 2;
    }
};

// lee
class Solution {
public:
    int longestString(int x, int y, int z) {
        return (min(x, y + 1) + min(x + 1, y) + z) * 2;
    }
};