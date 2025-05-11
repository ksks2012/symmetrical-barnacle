#include "include.h"

//endlesscheng
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int, int>; // Frequency, element value
        // L: maximum elements with frequency > x
        // R: other elements
        set<pii> L, R;

        long long sum_l = 0; // Sum of elements in L
        unordered_map<int, int> cnt;

        // insert number by frequency
        auto add = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            if (!L.empty() && p > *L.begin()) { // p is greater than the smallest in L
                sum_l += (long long) p.first * p.second;
                L.insert(p);
            } else {
                R.insert(p);
            }
        };

        // remove old frequency
        auto del = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            auto it = L.find(p);
            if (it != L.end()) {
                sum_l -= (long long) p.first * p.second;
                L.erase(it);
            } else {
                R.erase(p);
            }
        };

        // Balance the two sets
        auto l2r = [&]() {
            pii p = *L.begin();
            sum_l -= (long long) p.first * p.second;
            L.erase(p);
            R.insert(p);
        };
        auto r2l = [&]() {
            pii p = *R.rbegin();
            sum_l += (long long) p.first * p.second;
            R.erase(p);
            L.insert(p);
        };

        vector<int> res(nums.size() - k + 1);
        for (int r = 0; r < nums.size(); r++) {
            // Add in
            int in = nums[r];
            del(in);
            cnt[in]++;
            add(in);

            int l = r + 1 - k;
            if (l < 0) {
                continue;
            }

            // Maintain size
            while (!R.empty() && L.size() < x) {
                r2l();
            }
            while (L.size() > x) {
                l2r();
            }
            res[l] = sum_l;

            // Remove out
            int out = nums[l];
            del(out);
            cnt[out]--;
            add(out);
        }
        return res;
    }
};