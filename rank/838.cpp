#include "include.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';

        string res = "";
        for (int i = 0, j = 1; j < dominoes.length(); ++j) {
            if (dominoes[j] == '.') 
                continue;
            int mid = j - i - 1;
            if (i > 0)
                res += dominoes[i];
            if (dominoes[i] == dominoes[j])
                res += string(mid, dominoes[i]);
            else if (dominoes[i] == 'L' && dominoes[j] == 'R')
                res += string(mid, '.');
            else
                res += string(mid / 2, 'R') + string(mid % 2, '.') + string(mid / 2, 'L');
            i = j;
        }

        return res;
    }
};