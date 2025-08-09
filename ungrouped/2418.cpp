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

// kiran: This code sorts a list of people by their heights in descending order and returns their names in that order.
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
            vector<int> idx(names.size());
            for (int i = 0; i < names.size(); ++i) {
                idx[i] = i;
            }
            sort(idx.begin(), idx.end(), [&](int i, int j) {
                return heights[i] > heights[j];
            });
            vector<string> ans(names.size());
            for (int i = 0; i < names.size(); ++i) {
                ans[i] = names[idx[i]];
            }
            return ans;
        }
};