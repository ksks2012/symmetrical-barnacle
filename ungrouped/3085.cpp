#include "include.h"

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int tmp[26] = {0};

        for(auto c : word) {
            tmp[c - 'a']++;
        }

        vector<int> freq;
        for(int i = 0; i < 26; i++) {
            if(tmp[i] != 0) {
                freq.push_back(tmp[i]);
            }
        }
        sort(freq.begin(), freq.end(), greater<int>());

        int res = INT_MAX;
        for (int i = 0; i < freq.size(); i++) {
            int num = freq[i]; 
            int count = 0;

            // freq[i] + k
            for (int j = 0; j < freq.size(); j++) {
                if (freq[j] - num > k) {
                    count += freq[j] - (num + k);
                } else if (num > freq[j]) {
                    count += freq[j];
                }
            }
            res = min(res, count);
            if (count == 0) {
                break;
            }
        }

        return res;
    }
};

// endlesscheng
class Solution {
public:
    int minimumDeletions(string word, int k) {
        int cnt[26]{};
        for (char c: word) {
            cnt[c - 'a']++;
        }
        ranges::sort(cnt);

        int max_save = 0;
        for (int i = 0; i < 26; i++) {
            int sum = 0;
            for (int j = i; j < 26; j++) {
                // cnt[i] + k
                sum += min(cnt[j], cnt[i] + k);
            }
            max_save = max(max_save, sum);
        }
        return word.length() - max_save;
    }
};