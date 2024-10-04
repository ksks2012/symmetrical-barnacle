#include "include.h"

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;

        int n = skill.size();

        sort(skill.begin(), skill.end());
        int tmp = skill[0] + skill[n - 1];

        for (int i = 0; i < n / 2; i++) {
            if(skill[i] + skill[n - i - 1] != tmp) {
                return -1;
            }
            res += (long long)skill[i] * skill[n - i - 1];
        }

        return res;
    }
};