#include "include.h"

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());

        int apple_sum = 0;
        for(int i = 0; i < apple.size(); ++i) {
            apple_sum += apple[i];
        }
        vector<int> sum(capacity.size(), 0);
        for(int i = 0; i < capacity.size(); ++i) {
            if(i == 0) {
                sum[i] += capacity[i];
            } else {
                sum[i] += capacity[i] + sum[i - 1];
            }

            if(apple_sum <= sum[i]) {
                return i + 1;
            }
        }

        return 0;
    }
};