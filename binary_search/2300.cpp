#include "include.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        vector<int> res(m, 0);
        sort(potions.begin(), potions.end());

        for(int i = 0; i < m; i++) {
            res[i] = n - (lower_bound(potions.begin(), potions.end(), success / (double)spells[i]) - potions.begin());
        }

        return res;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        ranges::sort(potions);
        int m = spells.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            long long target = (success - 1) / spells[i];
            if (target < potions.back()) {
                res[i] = potions.end() - ranges::upper_bound(potions, (int) target);
            }
        }
        return res;
    }
};