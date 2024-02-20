#include "include.h"

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> tmp(n, 0);
        vector<int> sum(n + 1, 0);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int j = words[i].size();
            char check[2] = {words[i][0], words[i][j - 1]};
            for(int k = 0; k < 2; k++) {
                if(check[k] == 'a' || check[k] == 'e' || check[k] == 'i' || check[k] == 'o' || check[k] == 'u') {
                    tmp[i]++;
                }
            }
            cur += tmp[i] == 2;
            sum[i + 1] = cur;
        }

        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = sum[r + 1] - sum[l];
        }

        return ans;
    }
};