#include "include.h"

// votrubac
// enumeration
class Solution {
public:
    string minimizeResult(string expression) {
        int plus = expression.find('+');
        vector<int> v;
        vector<pair<int, int>> left_pair, right_pair;
        for (int left = stoi(expression.substr(0, plus)), mul = 10; left * 10 >= mul; mul *= 10)
            left_pair.push_back({ left / mul, left % mul}); 

        for (int right = stoi(expression.substr(plus + 1)), mul = 1; right / mul > 0; mul *= 10)
            right_pair.push_back({ right % mul, right / mul }); 

        for (auto [m1, s1] : left_pair) {
            for (auto [m2, s2]: right_pair) {
                if (v.empty() || max(1, m1) * (s1 + s2) * max(1, m2) < max(1, v[0]) * (v[1] + v[2]) * max(1, v[3]))
                    v = {m1, s1, s2, m2};
            }
        }
            
        return (v[0] ? to_string(v[0]) : "") + "(" + to_string(v[1]) + "+" + to_string(v[2]) + ")" + (v[3] ? to_string(v[3]) : "");
    }
};