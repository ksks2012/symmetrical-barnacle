#include "include.h"

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<int> pq[m];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pq[i].push(grid[i][j]);
            }
        }

        while(!pq[0].empty()) {
            int maxi = 0;
            for(int i = 0; i < m; i++) {
                maxi = max(maxi, pq[i].top());
                pq[i].pop();
            }
            res += maxi;
        }

        return res;
    }
};


class Solution {
public:
    static bool cmp(int a , int b){
        return a > b;
    }

    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> mat = grid;
        
        
        for(int i = 0; i < m; i++){
            sort(mat[i].begin(), mat[i].end(), cmp);
        }
        
        for(int j = 0; j < n; j++){
            vector<int> tmp(mat.size());
            for(int i = 0; i < m; i++){
               
                tmp.push_back(mat[i][j]);
            }
           
            sort(tmp.begin(), tmp.end(), cmp);
            
            ans = ans + tmp[0];
        }
        return ans;
    }
};