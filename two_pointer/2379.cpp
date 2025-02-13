#include "include.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int tmp = 0;
        for (int i = 0; i < k; i++) {
            tmp += blocks[i] == 'W';
        }

        int res = tmp;
        for(int i = k; i < n; i++) {
            tmp += blocks[i] == 'W';
            tmp -= blocks[i - k] == 'W';
            res = min(tmp, res);
        }

        return res;
    }
};
