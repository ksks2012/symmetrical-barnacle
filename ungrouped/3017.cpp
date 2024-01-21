#include "include.h"

// mhasan
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) {
            swap(x, y);
        }
        
        vector<long long> res(n + 2);
        if (x == y) {
            vector<long long> ans(n);
            for (int sz = 1, cnt = n - 1; cnt > 0; sz++, cnt--) {
                ans[sz - 1] += 2LL * cnt;
            }
            return ans;
        }
        
        auto getCircleDist = [&]() -> vector<int> {
            vector<int> res;
            res.emplace_back(1);
            int len = y - x + 1;
            for (int i = 0; i < (len - 1) / 2; i++) {
                res.emplace_back(2);
            }
            if (len % 2 == 0) {
                res.emplace_back(1);
            }
            return res;
        };
        
        auto addPairCircles = [&]() -> void {
            vector<int> circleDist = getCircleDist();
            int len = y - x + 1;
            int sz = (int) circleDist.size();
            for (int d = 0; d < sz; d++) {
                res[d] += 1LL * len * circleDist[d];
            }
        };
        
        auto addOutsideAndCircle = [&]() -> void {
            vector<int> circleDist = getCircleDist();
            int lft = x - 1;
            int rgt = n - y;
            for (int len : {lft, rgt}) {
                if (len == 0) {
                    continue;
                }
                vector<long long> cnt(n + 2);
                int sz = (int) circleDist.size();
                for (int d = 0; d < sz; d++) {
                    int l = min(d + 1, n + 1);
                    int r = min(l + len, n + 1);
                    cnt[l] += circleDist[d];
                    cnt[r] -= circleDist[d];
                }
                for (int i = 1; i <= n; i++) {
                    cnt[i] += cnt[i - 1];
                    res[i] += cnt[i] * 2LL;
                }
            }
        };
        
        auto addOutsidePair = [&]() -> void {
            int lft = x - 1;
            int rgt = n - y;
            for (int len : {lft, rgt}) {
                for (int sz = 1, cnt = len - 1; cnt > 0; sz++, cnt--) {
                    res[sz] += 2 * cnt;
                }
            }
            if (lft == 0 || rgt == 0) {
                return;
            }
            if (lft > rgt) {
                swap(lft, rgt);
            }
            for (int d = 3, cur = 1, cnt = 0; d <= n; d++, cur++) {
                if (cur > rgt) {
                    cnt--;
                } else if (cur <= lft) {
                    cnt++;
                }
                if (cnt <= 0) {
                    break;
                }
                res[d] += cnt * 2LL;
            }
        };
        
        addPairCircles();
        addOutsideAndCircle();
        addOutsidePair();
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = res[i + 1];
        }
        return ans;
    }
};