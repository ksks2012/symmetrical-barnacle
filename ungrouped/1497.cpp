#include "include.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int num : arr) {
            int mod = num % k;
            if (mod < 0) {
                mod += k;
            }
            mp[mod]++;
        }

        for (auto [mod, cnt] : mp) {
            if (mod == 0) {
                if (cnt % 2 != 0) {
                    return false;
                }
            } else if (mod * 2 == k) {
                if (cnt % 2 != 0) {
                    return false;
                }
            } else {
                if (mp[mod] != mp[k - mod]) {
                    return false;
                }
            }
        }

        return true;
    }
};