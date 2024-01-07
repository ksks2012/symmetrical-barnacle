#include "include.h"

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int idx = 0;

        for(int i = 0; i < dimensions.size(); i++) {
            int tmp = (dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if(tmp > ans) {
                idx = i;
                ans = tmp;
            }
            if(tmp == ans) {
                if(dimensions[idx][0] * dimensions[idx][1] < dimensions[i][0] * dimensions[i][1]) {
                    idx = i;
                }
            }
        }
        return dimensions[idx][0] * dimensions[idx][1];
    }
};