#include "../include.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
        for (auto i = 0; i < customers.size(); ++i) {
            satisfied += !grumpy[i] * customers[i];
            add_satisfied += grumpy[i] * customers[i];
            if (i >= minutes) 
                add_satisfied -= grumpy[i - minutes] * customers[i - minutes];
            m_add_satisfied = max(m_add_satisfied, add_satisfied);
        }
        return satisfied + m_add_satisfied;
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2]{}, maxi = 0;
        for (int i = 0; i < customers.size(); i++) {
            s[grumpy[i]] += customers[i];
            if (i < minutes - 1) {
                continue;
            }
            maxi = max(maxi, s[1]);
            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }
        return s[0] + maxi;
    }
};