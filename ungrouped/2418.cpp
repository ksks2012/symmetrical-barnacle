#include "include.h"

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }
        sort(people.begin(), people.end(), greater<pair<int, string>>());
        vector<string> res;
        for (const auto& person : people) {
            res.push_back(person.second);
        }

        return res;
    }
};