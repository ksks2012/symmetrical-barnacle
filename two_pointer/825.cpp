#include "../include.h"
    
// TL
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        for (int i = 0; i < ages.size(); i++) {
            for (int j = 0; j < ages.size(); j++) {
                if (i != j && isValid(ages[i], ages[j])) {
                    res++;
                }
            }
        }
        return res;
    }

    bool isValid(int age1, int age2) {
        return !(age1 <= 0.5 * age2 + 7 || age1 > age2 || (age1 > 100 && age2 < 100));
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int cnt[121]{};
        for (int age : ages) {
            cnt[age]++;
        }

        int res = 0, cnt_window = 0, age_y = 0;
        for (int age_x = 0; age_x < 121; age_x++) {
            cnt_window += cnt[age_x];
            if (age_y * 2 <= age_x + 14) {
                cnt_window -= cnt[age_y];
                age_y++;
            }
            if (cnt_window > 0) {
                res += cnt[age_x] * cnt_window - cnt[age_x];
            }
        }
        return res;
    }
};
