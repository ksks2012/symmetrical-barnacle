#include "include.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = arr.size();

        vector<int> sum(n + 1, 0);
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp ^= arr[i];
            sum[i + 1] = tmp;
        }

        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++) {
            ans[i] = sum[queries[i][1] + 1] ^ sum[queries[i][0]];
        }

        return ans;
    }
};