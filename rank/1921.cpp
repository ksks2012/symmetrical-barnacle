#include "../include.h"

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> tmp(n, 0);
        for(int i = 0; i < n; i++) {
            tmp[i] = (dist[i] - 1) / speed[i];
        }
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < n; i++) {
            if(tmp[i] < i)
                return i;                
        }
        
        return tmp.size();
    }
};