#include <bits/stdc++.h>
using namespace std;

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


// Lee
class Solution {
    struct VecHash {
        size_t operator()(const vector<int>& v) const noexcept {
            // simple 64-bit rolling hash
            uint64_t h = 1469598103934665603ULL;
            for (int x : v) {
                h ^= (uint64_t)(x + 0x9e3779b9);
                h *= 1099511628211ULL;
            }
            return (size_t)h;
        }
    };
    struct VecEq {
        bool operator()(const vector<int>& a, const vector<int>& b) const noexcept {
            return a == b;
        }
    };

    int test_substr(const string &s, int L, int R) {
        if (L >= R) return 0;
        array<bool, 256> seen{};
        vector<unsigned char> chs;
        chs.reserve(16);
        for (int i = L; i < R; ++i) {
            unsigned char c = (unsigned char)s[i];
            if (!seen[c]) {
                seen[c] = true;
                chs.push_back(c);
            }
        }
        int m = (int)chs.size();
        if (m == 0) return 0;

        array<int, 256> count{};
        vector<int> key(m, 0);
        unordered_map<vector<int>, int, VecHash, VecEq> pos;
        pos.reserve((R - L) * 2 + 4);
        // initial key (all zeros) at position L-1
        pos.emplace(key, L - 1);

        int res = 0;
        for (int i = L; i < R; ++i) {
            unsigned char c = (unsigned char)s[i];
            ++count[c];
            int base = count[chs[0]];
            for (int j = 0; j < m; ++j) key[j] = count[chs[j]] - base;
            auto it = pos.find(key);
            if (it != pos.end()) {
                res = max(res, i - it->second);
            } else {
                pos.emplace(key, i);
            }
        }
        return res;
    }

public:
    int longestBalanced(const string &s) {
        int n = (int)s.size();
        if (n == 0) return 0;

        // res1: longest run of the same character
        int res1 = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                ++cur;
                res1 = max(res1, cur);
            } else {
                cur = 1;
            }
        }

        // res2: for separators 'a','b','c', split and run test_substr on each piece (avoid substr copies)
        int res2 = 0;
        for (char sep : {'a','b','c'}) {
            int start = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == sep) {
                    if (i - start > 0) res2 = max(res2, test_substr(s, start, i));
                    start = i + 1;
                }
            }
            if (start < n) res2 = max(res2, test_substr(s, start, n));
        }

        // res3: test on whole string
        int res3 = test_substr(s, 0, n);

        return max({res1, res2, res3});
    }
};