#include "include.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int res = 0;
        int sumEnergy = 0;
        for(int i = 0; i < n; i++) {
            sumEnergy += energy[i];
        }
        if(initialEnergy <= sumEnergy) {
            res += sumEnergy - initialEnergy + 1;
        }

        int currExperience = initialExperience;
        for(int i = 0; i < n; i++) {
            if(currExperience <= experience[i]) {
                res += experience[i] - currExperience + 1;
                currExperience = experience[i] + 1;
            }
            currExperience += experience[i];
        }

        return res;
    }
};