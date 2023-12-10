#include "../include.h"

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        int m = v.size();
        int n = v[0].size();

        vector<int> ans;

        for(int i = 0; i < m; i++) {
            int a = 1;
            for(int j = 0; j < v[i][1]; j++) {
                a = (a * v[i][0]) % 10;
            }
            int b = 1;
            for(int j = 0; j < v[i][2]; j++) {
                b = (b * a) % v[i][3];
            }
            if(b == target)
                ans.push_back(i);
        }

        return ans;
    }
};