#include "include.h"

class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        int n = num_str.size();
        int maxi = num;

        // Try all possible swaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(num_str[i], num_str[j]); 
                maxi = max(maxi, stoi(num_str));
                swap(num_str[i], num_str[j]);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num), back = res;
        for (int i = back.size() - 2; i >= 0; --i) {
            back[i] = max(back[i], back[i + 1]);
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == back[i]) 
                continue;
            for (int j = res.size() - 1; j > i; --j) {
                if (res[j] == back[i]) {
                    swap(res[i], res[j]);
                    return stoi(res);
                }
            }
        }
        return stoi(res);
    }
};