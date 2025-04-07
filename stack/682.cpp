#include "include.h"

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> tmp;
        for (auto&& i : operations) {
            if (i == "C") {
                tmp.pop();
            } else if (i == "D") {
                int t = tmp.top();
                tmp.push(t * 2);
            } else if (i == "+") {
                int t1 = tmp.top();
                tmp.pop();
                int t2 = tmp.top();
                tmp.push(t1);
                tmp.push(t1 + t2);
            } else {
                tmp.push(stoi(i));
            }
        }

        int res = 0;
        while (!tmp.empty()) {
            res += tmp.top();
            tmp.pop();
        }
        return res;
    }
};