#include "include.h"

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> tmp;
        int res = 0;
        for (auto& word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= 1 << (c - 'a');
            }
            res += tmp[mask]++;
        }
        return res;
    }
};