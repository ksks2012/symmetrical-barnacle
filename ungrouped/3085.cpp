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