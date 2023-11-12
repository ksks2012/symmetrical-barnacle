#include "../include.h"

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;

        map<string, vector<string>> m;
        for(int i = 0; i < access_times.size(); i++) {
            if(m.find(access_times[i][0]) == m.end()) {
                m[access_times[i][0]] = vector<string>();
            }
            m[access_times[i][0]].push_back(access_times[i][1]);
        }
        for(auto &i: m) {
            int count = 0;
            vector<int> tmp;
            if(i.second.size() < 3) {
                continue;
            }
            sort(i.second.begin(), i.second.end());
            for(int j = 0; j < i.second.size() - 1; j++) {
                tmp.push_back(stoi(i.second[j + 1]) - stoi(i.second[j]));
            }
            for(int j = 0; j < tmp.size() - 1; j++) {
                if(tmp[j] + tmp[j + 1] < 100) {
                    count++;
                }
            }
            if(count > 0) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};