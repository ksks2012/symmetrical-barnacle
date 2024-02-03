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
    int maximumGroups(vector<int> &grades) {
        int left = 1, right = 446, n = grades.size();
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (mid * (mid + 1) / 2 <= n)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
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

// Greedy
class Solution {
public:
    int maximumGroups(vector<int> &g) {
        sort(g.begin(), g.end());
        int pre_sum = 0;
        int k = 0;
        int n = g.size();
        for(int i = 0; i < n; i++) {
            int tmp = i, sum = 0;
            for(; i < n && sum <= pre_sum || i <= tmp + k; i++) {
                sum += g[i];
            }
            if(sum <= pre_sum) {
                break;
            }
            pre_sum = sum;
            k = i - tmp;
        }
        return 
    }
};
