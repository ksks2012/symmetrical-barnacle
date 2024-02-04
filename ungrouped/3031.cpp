#include "include.h"

// Z-function
// Time complexity: O(m + n)
class Solution {
public:
    int minimumTimeToInitialState(const string &word, int k) {
        int res = 1, n = word.size();
        auto z = z_function(word);
        for (; k * res < n; ++res)
            if (z[k * res] >= n - k * res)
                break;
        return res;
    }
    
    vector<int> z_function(const string &s) {
        int n = s.size(), left = 0, right = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i < right)
                z[i] = min(right - i, z[i - left]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if(i + z[i] > right) {
                left = i;
                right = i + z[i];
            }
        }
        return z;
    }
};