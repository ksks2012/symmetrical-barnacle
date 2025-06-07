#include "../include.h"

class Solution {
public:
    int clumsy(int N) {
        int op = 0;
        std::stack<int> stk;
        stk.push(N);
        for (int i = N - 1; i > 0; --i) {
            if (op == 0) {
                int tmp = stk.top(); stk.pop();
                stk.push(tmp * i);
            } else if (op == 1) {
                int tmp = stk.top(); stk.pop();
                stk.push(tmp / i);
            } else if (op == 2) {
                stk.push(i);
            } else if (op == 3) {
                stk.push(-i);
            }
            op = (op + 1) % 4;
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};