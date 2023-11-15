#include "../include.h"

class Solution {
public:
    vector<vector<int>> tmp;
    int DFS(vector<bool>& hasApple,int node,int d, int prev) {
        int result=0,temp;
        for(int &i : tmp[node])
	    if(i != prev) {
	        temp = DFS(hasApple, i, d + 1, node);
	        if(temp) 
                result += temp - d;
	    }
        return result || hasApple[node] ? result + d : 0; 
        
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        tmp.resize(n);
        // copy edges
        for(auto &e : edges)
            tmp[e[0]].push_back(e[1]), tmp[e[1]].push_back(e[0]);

        return DFS(hasApple, 0, 0, -1) * 2;
    }
};