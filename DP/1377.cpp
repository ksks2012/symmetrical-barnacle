#include "include.h"


// endlesscheng
class Solution {
public:
    int t;
    int target;
    double ans = 0;
    vector<vector<int>> graph;
    int DFS(int x, int parent, int left_time, long long prod) {
        if (x == target && (left_time == 0 || graph[x].size() == 1)) {
            ans = 1.0 / prod;
            return true;
        }
        if (x == target || left_time == 0) 
            return false;
        for (int y: graph[x])  
            if (y != parent && DFS(y, x, left_time - 1, prod * (graph[x].size() - 1)))
                // find target
                return true;
        // not find target
        return false;
    }

    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        graph = vector<vector<int>>(n + 1);
        graph[1] = {0};
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        this->t = t;
        this->target = target;

        DFS(1, 0, t, 1);
        return ans;
    }
};

// WA
class Solution {
public:
    int t;
    int target;
    int match = 0;
    vector<vector<int>> graph;

    int DFS(int x, int cur, vector<int> visited) {
        // cout << x << " " << cur << endl;
        if(cur == 0) {
            if(x == target)
                match++;
            return 1;
        }
            
        int res = 0;
        bool jump = false;
        for(int y: graph[x]) {
            if(visited[y] == 0) {
                visited[y] = 1;
                res += DFS(y, cur - 1, visited);           
                visited[y] = 0;     
                jump = true;
            }
        }
        if(jump != true)
            res += DFS(x, cur - 1, visited);

        return res;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        graph = vector<vector<int>>(n + 1);
        vector<int> visited(n + 1, 0);

        this->t = t;
        this->target = target;

        for(auto e: edges) {
            int x = e[0];
            int y = e[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int pos = DFS(1, t, visited);

        return (double)match / pos;
    }
};
