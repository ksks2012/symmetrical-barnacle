#include "include.h"

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house: houses) {
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j - 1;
            int right_dis = j >= heaters.size() ? INT_MAX : heaters[j] - house;
            int left_dis = i < 0 ? INT_MAX : house - heaters[i];
            int cur_dis = min(left_dis, right_dis);
            res = max(res, cur_dis);
        }
        return res;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int n = heaters.size(), j = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); ++i) {
            int cur = houses[i];
            while (j < n - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) {
                ++j;
            }
            res = max(res, abs(heaters[j] - cur));
        }
        return res;
        
        
    }
};