#include "include.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        if (k <= numOnes) {
            res = k;
        } else if (k <= numOnes + numZeros) {
            res = numOnes;
        } else {
            res = numOnes - (k - numOnes - numZeros);
        }
        return res;
    }
};