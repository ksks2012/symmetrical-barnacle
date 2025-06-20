#include "include.h"

// Vlad
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favs) {
        for (auto &comps : favs)
            sort(begin(comps), end(comps));

        vector<int> res;
        for (auto i = 0; i < favs.size(); ++i) {
            bool notSubset = true;
            for (auto j = 0; j < favs.size() && notSubset; ++j) {
                if (i == j)
                    continue;
                
                    notSubset = !includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
            }
            if (notSubset)
                res.push_back(i);
        }
        return res;
    }
};