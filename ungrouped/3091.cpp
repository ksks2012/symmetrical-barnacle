#include "include.h"

class Solution {
public:
    int minOperations(int k) {
        int sqr = (sqrt(k));
        if(k % sqr != 0)
            sqr++;
        int target = k / sqr;
        if(k % sqr != 0)
            target++;

        return sqr + target - 2;
    }
};
