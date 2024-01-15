#include "include.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq_s1(26, 0);

        int m = s1.size();
        int n = s2.size();

        if(m > n)
            return false;

        for(int i = 0; i < m; i++) {
            freq_s1[s1[i] - 'a']++;
        }

        vector<int> freq_s2(26, 0);

        int left = 0, right = 0;
        while(right < n) {
            freq_s2[s2[right] - 'a']++;
            if(right - left + 1 == m) {
                if(freq_s1 == freq_s2)
                    return true;
            }
            if(right - left + 1 < m)
                right++;
            else {
                freq_s2[s2[left] - 'a']--;
                left++;
                right++;
            }
        }

        return false;
    }
};