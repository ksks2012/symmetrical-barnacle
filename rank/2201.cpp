#include "../include.h"

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int m[1001][1001] = {0};
        for (auto& d : dig) {
            m[d[0]][d[1]] = 1;
        }

        int res = 0;
        for(auto& a : artifacts) {
            bool check = true;
            for(int i = a[0]; i <= a[2]; i++) {
                for(int j = a[1]; j <= a[3]; j++) {
                    if(m[i][j] == 0) {
                        check = false;
                        break;
                    }
                }
            }
            if(check) {
                res++;
            }
        }

        return res;
    }
};