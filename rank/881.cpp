#include "../include.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int res = 0;

        int left = 0, right = people.size() - 1;

        while(left <= right) {
            if(people[left] + people[right] <= limit) {
                res++;
                left++;
                right--;
            } else if(people[right] <= limit) {
                res++;
                right--;
            } else {
                right--;
            }
        }

        return res;
    }
};