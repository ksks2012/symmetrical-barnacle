#include "include.h"

class Solution {
public:
    int minimumPartition(string s, int k) {
        long long tmp = 0;
        int res = 1;
        for(int i = 0; i < s.size(); i++) {
            tmp = tmp * 10 + s[i] - '0';
            if(tmp > k) {
                res++;
                tmp = s[i] - '0';
            }
            if(tmp > k)
                return -1;
        }

        return res;
    }
};