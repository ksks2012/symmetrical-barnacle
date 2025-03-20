#include "include.h"

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> tmp;
        for (int x : nums) {
            auto it = tmp.find(k - x);
            if (it != tmp.end() && it->second) {
                it->second--;
                res++;
            } else {
                tmp[x]++;
            }
        }
        return res;
    }
};