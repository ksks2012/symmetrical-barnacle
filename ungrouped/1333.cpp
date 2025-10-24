#include "include.h"

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> filtered; // pair<rating, id>
        for (const auto& r : restaurants) {
            if ((veganFriendly == 1 && r[2] == 0) || r[3] > maxPrice || r[4] > maxDistance) {
                continue;
            }
            filtered.emplace_back(r[1], r[0]);
        }

        sort(filtered.begin(), filtered.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // Sort by rating descending
            }
            return a.second > b.second; // Sort by id descending
        });

        vector<int> res;
        for (const auto& p : filtered) {
            res.push_back(p.second);
        }

        return res;
    }
};