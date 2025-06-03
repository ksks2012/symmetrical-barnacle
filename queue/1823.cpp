#include "include.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> tmp;
        for (int i = 1; i <= n; ++i) {
            tmp.push_back(i);
        }
        int cur_ind = 0;

        while (tmp.size() > 1) {
            int next_to_remove = (cur_ind + k - 1) % tmp.size();
            tmp.erase(tmp.begin() + next_to_remove);
            cur_ind = next_to_remove;
        }

        return tmp[0];
    }
};