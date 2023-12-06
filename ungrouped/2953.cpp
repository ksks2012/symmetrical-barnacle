#include "include.h"

class Solution {
public:
    bool checkfreq(unordered_map<char, int>& freq, int k) {
        for (auto& pair : freq) {
            if (pair.second != k && pair.second != 0) {
                return false;
            }
        }
        return true;
    }
    int countCompleteSubstrings(string word, int k) {
        vector<pair<int, int>> splits;
        int ans = 0;
        int len = word.size();
        for(int i = 0; i < len; i++) {
            int temp = i;
            if(i < len - 1) {
                while(i < len - 1 && abs(word[i+1] - word[i]) <= 2) {
                    i++;
                }
                splits.push_back(make_pair(temp, i + 1));
            }
            else {
                splits.push_back(make_pair(len - 1, len));
            }
        }
        for(auto x: splits) {
            int start = x.first, end = x.second, len = end - start + 1;
            for(int windowsize = k; windowsize <= min(len, 26 * k); windowsize += k) {
                int windowstart = start, windowend = windowstart + windowsize - 1;
                unordered_map<char, int> freq;
                for(int j = windowstart; j <= windowend; j++) {
                    freq[word[j]]++;
                }
                while (windowend < end) {
                    if (checkfreq(freq, k)) {
                        ans++;
                    }
                    freq[word[windowstart]]--;
                    windowstart++;
                    windowend++;
                    freq[word[windowend]]++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countCompleteSubstrings(string word, int K) {
        int n = word.size();

        // f[i][c] length i prefix has how many char c
        int f[n + 1][26];
        for(int i = 0; i < 26; i++) {
            f[0][i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 26; j++) {
                f[i][j] = f[i - 1][j];
            }
            f[i][word[i - 1] - 'a']++;
        }

        long long ans = 0;
        // last i, section start at j
        for(int i = 1, j = 0; i <= n; i++) {
            if(i > 1 && abs(word[i - 1] - word[i - 2]) > 2)
                j = i - 1;
            
            for(int fac = 1, L = i - K; fac <= 26 && L >= j; fac++, L-= K) {
                bool ok = true;
                // check char nums
                for(int k = 0; k < 26; k++) {
                    int det = f[i][k] - f[L][k];
                    if(det != 0 && det != K) {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    ans++;
            }
        }
        return ans;
    }
};

// From https://leetcode.cn/problems/count-complete-substrings/solutions/2551743/bao-li-hua-chuang-mei-ju-chuang-kou-nei-31j5m/
class Solution {
    int f(string s, int k) {
        int res = 0;
        for (int m = 1; m <= 26 && k * m <= s.length(); m++) {
            int cnt[26]{};
            auto check = [&]() {
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] && cnt[i] != k) {
                        return;
                    }
                }
                res++;
            };
            for (int right = 0; right < s.length(); right++) {
                cnt[s[right] - 'a']++;
                int left = right + 1 - k * m;
                if (left >= 0) {
                    check();
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }

public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n;) {
            int st = i;
            for (i++; i < n && abs(int(word[i]) - int(word[i - 1])) <= 2; i++);
            ans += f(word.substr(st, i - st), k);
        }
        return ans;
    }
};