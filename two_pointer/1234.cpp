#include "include.h"

// WA
class Solution {
public:
    int balancedString(string s) {
        int tmp[4] = {0};
        unordered_map<char, int> m;
        m['Q'] = 0;
        m['W'] = 1;
        m['E'] = 2;
        m['R'] = 3;

        int n = s.length();

        for(int i = 0; i < n; i++) {
            tmp[m[s[i]]]++;
        }

        int ans = 0;
        int target = n / 4;
        for(int i = 0; i < 4; i++) {
            ans += abs(tmp[i] - target);
        }

        return ans / 2;
    }
};

// lee
class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        int n = s.length();
        int res = n;
        int left = 0;
        int k = n / 4;
        for (int j = 0; j < n; ++j) {
            count[s[j]]++;
        }
        for (int right = 0; right < n; ++right) {
            count[s[right]]--;
            while (left < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                res = min(res, right - left + 1);
                count[s[left++]] += 1;
            }
        }
        return res;
    }
};
