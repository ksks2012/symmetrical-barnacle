#include "../include.h"

class Solution {
public:
    long long helper(vector<int>& time, long long give) {
        long long total = 0;
        for(auto t: time) {
            long long val = t;
            total += (give / val);
        }
        return total;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;

        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(helper(time, mid) >= totalTrips) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};