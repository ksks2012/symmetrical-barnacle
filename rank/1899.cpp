#include "include.h"

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tmp(3, 0);

        for(auto t: triplets) {
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                tmp[0] = max(tmp[0], t[0]);
                tmp[1] = max(tmp[1], t[1]);
                tmp[2] = max(tmp[2], t[2]);
            }
        }
        return tmp == target;
    }
};