#include "include.h"

class Solution {
public:
    vector<int> find_div(int num) {
        int n = sqrt(num);
        for(int i = n; i >= 1; i--) {
            if(num % i == 0) {
                return {i, num / i};
            }
        }
        return {1, num};
    }

    vector<int> closestDivisors(int num) {
        vector<int> a = find_div(num + 1);
        vector<int> b = find_div(num + 2);

        if(abs(a[0] - a[1]) < abs(b[0] - b[1]))
            return a;
        return b;
    }
};