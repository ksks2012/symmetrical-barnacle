#include "include.h"

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> res;

        unordered_map<string, vector<int>> m;
        for (int i = 0; i < keyName.size(); ++i) {
            int time = stoi(keyTime[i].substr(0, 2)) * 60 + stoi(keyTime[i].substr(3));
            m[keyName[i]].push_back(time);
        }

        for(auto k : m) {
            sort(begin(k.second), end(k.second));
            for (int i = 2; i < k.second.size(); ++i) {
                if (k.second[i] - k.second[i - 2] <= 60) {
                    res.push_back(k.first);
                    break;
                }
            }
        }
        // Result should be sorted
        sort(begin(res), end(res));
        return res;
    }
};