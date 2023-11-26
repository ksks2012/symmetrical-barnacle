#include "../include.h"

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) 
            return {0};
        vector<int> ans{0, 1};
        int k = 2, i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num) 
                    break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t) 
                    ans.push_back(ans[i - t]);
                else 
                    ans.push_back(ans[i - t] + 1);
            }
            ++k;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) 
            return {0};
        vector<int> ans(num + 1, 0);
        int x = 0;
        int b = 1;

        // [0, b) is calculated
        while (b <= num) {
            // generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= num) {
                ans[x + b] = ans[x] + 1;
                ++x;
            }
            x = 0; // reset x
            b <<= 1; // b = 2b
        }
        return ans;
    }
};