#include "include.h"

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        unordered_map<int, int> count;

        for (int num : changed) {
            count[num]++;
        }

        sort(changed.begin(), changed.end());
        for (int num : changed) {
            if (count[num] == 0) continue; // Skip if already used

            if (count[num * 2] > 0) {
                res.push_back(num);
                count[num]--;
                count[num * 2]--;
            } else {
                return {}; // If we can't find a pair, return empty
            }
        }
        if (res.size() * 2 != changed.size()) {
            return {}; // If the size of the original array is not half of changed, return empty
        }

        return res;
    }
};