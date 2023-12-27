#include "include.h"

// DFS
class Solution {
public:
    string colors;
    vector<int> neededTime;

    int DFS(int x, int y) {
        if(x < 0)
            return 0;

        if(y == -1) {
            return DFS(x - 1, x);
        }

        if(colors[x] == colors[y])
            return min(DFS(x - 1, x) + neededTime[y], DFS(x - 1, y) + neededTime[x]);

        return DFS(x - 1, x);
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        this->colors = colors;
        this->neededTime = neededTime;
        return DFS(n - 1, -1);
    }
};

// MLE
class Solution {
public:
    string colors;
    vector<int> neededTime;

    int DFS(int x, int y, vector<vector<int>> &memo) {
        if(x < 0)
            return 0;
        
        if(y == -1) {
            return DFS(x - 1, x, memo);
        }
        int &res = memo[x][y];
        if(res != -1)
            return res;

        if(colors[x] == colors[y])
            return res = min(DFS(x - 1, x, memo) + neededTime[y], DFS(x - 1, y, memo) + neededTime[x]);

        return res = DFS(x - 1, x, memo);
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        this->colors = colors;
        this->neededTime = neededTime;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(n - 1, -1, memo);
    }
};

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        for(int i = 1; i < neededTime.size(); i++) {
            if(colors[i] == colors[i-1]) {
                res += min(neededTime[i], neededTime[i-1]);
                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }
        return res;
    }
};


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            if(colors[i] == colors[i + 1]) {
                sum += min(neededTime[i], neededTime[i + 1]); 
                if(neededTime[i] > neededTime[i + 1])
                    swap(neededTime[i], neededTime[i + 1]);
            }
        }
        return sum;
    }
};