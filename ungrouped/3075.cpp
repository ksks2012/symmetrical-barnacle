#include "include.h"

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;

        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), greater<int>());

        int minus = 0;

        for(int i = 0; i < k && i < n; i++) {
            if(happiness[i] - minus > 0){
                sum += happiness[i] - minus;
                minus++;
            } else {
                break;
            }
        }

        return sum;
    }
};