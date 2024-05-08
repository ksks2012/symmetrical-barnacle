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