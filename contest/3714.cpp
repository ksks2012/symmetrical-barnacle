#include "include.h"

class Solution {
public:
    void dfs(string& s, char x, char y, int& maxi) {
        int n = s.size();

        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == x) {
                sum += 1;
            } else if (s[i] == y) {
                sum -= 1;
            } else {
                mp.clear();
                mp[0] = i;
                sum = 0;
                continue;
            }

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
    }

    int longestBalanced(string s) {
        int n = s.size();

        int res = 1;

        // 1. All same characters
        int len = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                len++;
            } else {
                res = max(res, len);
                len = 1;
            }
        }
        res = max(res, len);

        // 2. Two distinct characters
        dfs(s, 'a', 'b', res);
        dfs(s, 'b', 'c', res);
        dfs(s, 'a', 'c', res);

        // 3. All three have same frequency
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;

            int countAB = count[0] - count[1];
            int countAC = count[0] - count[2];

            if (mp.find({countAB, countAC}) != mp.end()) {
                res = max(res, i - mp[{countAB, countAC}]);
            } else {
                mp[{countAB, countAC}] = i;
            }
        }

        return res;
    }
};

