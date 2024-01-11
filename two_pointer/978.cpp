#include "include.h"

// Sliding window
class Solution {
public:
    int cmp(int x, int y) {
        if(x > y)
            return 1;
        if(x < y)
            return -1;
        return 0;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        int ans = 1;
        int tmp = 0;

        for(int i = 1; i < n; i++) {
            int cur = cmp(arr[i - 1], arr[i]);

            if(cur == 0) {
                tmp = i;
            } else if(i == n - 1 || cur * cmp(arr[i], arr[i + 1]) != -1) {
                ans = max(ans, i - tmp + 1);
                tmp = i;
            }
            
        }
        return ans;
    }
};