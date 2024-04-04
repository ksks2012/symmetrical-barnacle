#include "include.h"

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> tmp(n, 0);
        long long res = 0;

        for(int i = 0; i < roads.size(); i++) {
            tmp[roads[i][0]]++;
            tmp[roads[i][1]]++;
        }
        
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < n; i++) {
            res += tmp[i] * (i + 1);
        }

        return res;
    }
};