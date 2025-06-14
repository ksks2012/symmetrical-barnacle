#include "include.h"

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }

        int res = -1;
        for (const auto& [num, cnt] : count) {
            if (num == cnt) {
                res = max(res, num);
            }
        }
        
        return res;
    }
};