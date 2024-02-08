#include "include.h"

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> sum(n, 0);

        int cur_zero = 0;
        int cur_one = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                cur_zero++;
            }
            sum[i] += cur_zero;

            if(s[n - 1 - i] == '1') {
                cur_one++;
            }
            // one[n - 1 - i] = cur_one;
            sum[n - 1 - i] += cur_one;
        }
        return *max_element(sum.begin(), sum.end());
    }
};

class Solution {
public:
    int maxScore(const std::string& s) {
        int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = std::count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = std::max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};
