#include "include.h"

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto helper = [&](long long m) {
            int left_h = mountainHeight;
            for (int t : workerTimes) {
                left_h -= ((int) sqrt(m / t * 8 + 1) - 1) / 2;
                if (left_h <= 0) {
                    return true;
                }
            }
            return false;
        };

        int maxi = ranges::max(workerTimes);
        int h = (mountainHeight - 1) / workerTimes.size() + 1;
        long long left = 0, right = (long long) maxi * h * (h + 1) / 2;
        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            (helper(mid) ? right : left) = mid;
        }
        return right;
    }
};

typedef tuple<long long, long long, int> T;
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<T, vector<T>, greater<>> pq;
        for (int t : workerTimes) {
            pq.emplace(t, t, t);
        }
        long long res = 0;
        while (mountainHeight--) {
            auto [nxt, delta, base] = pq.top(); 
            pq.pop();
            res = nxt;
            pq.emplace(nxt + delta + base, delta + base, base);
        }
        return res;
    }
};