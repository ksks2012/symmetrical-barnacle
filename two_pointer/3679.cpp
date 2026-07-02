#include "../include.h"

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> mp;
        int n = arrivals.size();
        int res = 0;

        int left = 0;
        for(int right = 0; right < n; right++) {
            if(mp[arrivals[right]] >= m) {
                res++;
                arrivals[right] = 0;
            } else {
                mp[arrivals[right]]++;
            }

            left = right - w + 1;
            if (left >= 0) {
                mp[arrivals[left]]--;
            }
        }
        return res;
    }
};