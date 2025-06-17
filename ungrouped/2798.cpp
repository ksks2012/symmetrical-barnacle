#include "../include.h"

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target) {
                res++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(begin(hours), end(hours), [&](int h) {
            return h >= target; 
        });
    }
};
