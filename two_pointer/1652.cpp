#include "include.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        int right = k > 0 ? k + 1 : n;
        k = abs(k);
        int s = reduce(code.begin() + right - k, code.begin() + right); // ans[0]
        for (int i = 0; i < n; i++) {
            ans[i] = s;
            s += code[right % n] - code[(right - k) % n];
            right++;
        }
        return ans;
    }
};