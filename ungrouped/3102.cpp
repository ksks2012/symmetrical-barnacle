#include "include.h"

// votrubac
class Solution {
public:
    array<long long, 3> maxDistance(vector<vector<int>>& ps, int skip = -1) {
        int sum[2] = {INT_MAX, INT_MIN}, sum_i[2] = {0, 0};
        int diff[2] = {INT_MAX, INT_MIN}, diff_i[2] = {0, 0};
        for (int i = 0; i < ps.size(); ++i) {
            if (i == skip)
                continue;
            if (sum[0] > ps[i][0] + ps[i][1]) {
                sum[0] = ps[i][0] + ps[i][1];
                sum_i[0] = i;
            }
            if (sum[1] < ps[i][0] + ps[i][1]) {
                sum[1] = ps[i][0] + ps[i][1];
                sum_i[1] = i;
            }
            if (diff[0] > ps[i][0] - ps[i][1]) {
                diff[0] = ps[i][0] - ps[i][1];
                diff_i[0] = i;
            }
            if (diff[1] < ps[i][0] - ps[i][1]) {
                diff[1] = ps[i][0] - ps[i][1];
                diff_i[1] = i;
            }
        }
        if (sum[1] - sum[0] > diff[1] - diff[0])
            return {sum[1] - sum[0], sum_i[0], sum_i[1]};
        return {diff[1] - diff[0], diff_i[0], diff_i[1]};
    }
    int minimumDistance(vector<vector<int>>& ps) {
        auto [res, i, j] = maxDistance(ps);
        return min(maxDistance(ps, i)[0], maxDistance(ps, j)[0]);
    }
};