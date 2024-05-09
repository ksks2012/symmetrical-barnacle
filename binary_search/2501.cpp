#include "include.h"

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        
        unordered_set<int> visited;
        unordered_set<int> tmp;
        for(int i = 0; i < m; i++) {
            tmp.insert(nums[i]);
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            long long next = (long long)nums[i] * nums[i];
            int cur = 1;
            visited.insert(nums[i]);
            while(visited.find(next) == visited.end() && tmp.find(next) != tmp.end()) {
                cur++;
                visited.insert(next);
                next = next * next;
            }
            res = max(res, cur);
        }


        return res < 2 ? -1 : res;
    }
};