#include "include.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }   
        }
        return left;
    }
};

// lee
// Golden section search version
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto gold1 = [](int l, int r) {
            return l + int(round((r - l) * 0.382));
        };
        auto gold2 = [](int l, int r) {
            return l + int(round((r - l) * 0.618));
        };
        int l = 0, r = arr.size() - 1;
        int x1 = gold1(l, r), x2 = gold2(l, r);
        while (x1 < x2) {
            if (arr[x1] < arr[x2]) {
                l = x1;
                x1 = x2;
                x2 = gold1(x1, r);
            } else {
                r = x2;
                x2 = x1;
                x1 = gold2(l, x2);
            }
        }
        auto it = max_element(arr.begin() + l, arr.begin() + r + 1);
        return distance(arr.begin(), it);
    }
};
