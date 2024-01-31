#include "include.h"

// lee
class Solution {
public:
    int maximumGroups(vector<int> &grades) {
        int k = 0, total = 0, n = grades.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
    }
};

class Solution {
public:
    int maximumGroups(vector<int> &g) {
        int left = 1;
        int right = 1000;
        int mid = left + (right - left) / 2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int sum = mid * (mid + 1) / 2;
            int tmp = (mid + 2) * (mid + 1) / 2;
            if (sum == g.size()) {
                return mid;
            } else if (g.size() > sum && g.size() < tmp) {
                return mid;
            } else if (sum > g.size()) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return mid;
    }
};