#include "include.h"

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> ans;
        vector<int> pre(n, 0), suf(n, 0);

        int cur = 1;
        pre[0] = 1;
        for(int i = 1; i < n; i++) {
            if(security[i] <= security[i - 1]) {
                cur++;
                
            } else {
                cur = 1;
            }
            pre[i] = cur;
        }

        cur = 1;
        suf[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(security[i] <= security[i + 1]) {
                cur++;
            } else {
                cur = 1;
            }
            suf[i] = cur;
        }

        for(int i = 0; i < n; i++) {
            if(pre[i] - 1 >= time && suf[i] - 1 >= time)
                ans.push_back(i);
        }

        return ans;
    }
};