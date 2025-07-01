#include "../include.h"

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                res.push_back(i);
                res.push_back(-i);
            }
        } else {
            for (int i = 1; i <= n / 2; i++) {
                res.push_back(i);
                res.push_back(-i);
            }
            res.push_back(0);
        }   


        return res;
    }
};