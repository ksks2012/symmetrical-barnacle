#include "include.h"

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> x;

        for(int i = 0; i < points.size(); i++) {
            x.insert(points[i][0]);
        }

        int res = 0;
        if(w == 0) {
            return x.size();
        }
        vector<int> tmp(x.begin(), x.end());
        vector<int> interval;
        for(int i = 1; i < tmp.size(); i++) {
            interval.push_back(tmp[i] - tmp[i - 1]);
        }
        
        int left = 0;
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i] - tmp[left] == w) {
                res++;
                left = i + 1;
            } else if(tmp[i] - tmp[left] > w) {
                res++;
                left = i;
            }   
        }
        if(left != tmp.size())
            res++;

        return res;
    }
};