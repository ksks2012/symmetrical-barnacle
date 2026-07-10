#include "include.h"
    
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        int max_y = 0;
        for (auto& sq : squares) {
            int length = sq[2];
            total_area += 1LL * length * length;
            max_y = max(max_y, sq[1] + length);
        }

        auto check = [&](double y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                double yi = sq[1];
                if (yi < y) {
                    double length = sq[2];
                    area += length * min(y - yi, length);
                }
            }
            return area >= total_area / 2.0;
        };

        double left = 0, right = max_y;
        for (int i = 0; i < 47; i++) {
            double mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return (left + right) / 2;
    }
};