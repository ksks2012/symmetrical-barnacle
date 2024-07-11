#include "include.h"

class Solution {
public:
    vector<vector<string>> mostPopularCreator(
        const vector<string>& creators, const vector<string>& ids, const vector<int>& views) {
        const int n = size(creators);
        unordered_map<string, tuple<long, long, string>> m;
        long tmp = 0;
        
        for (int i = 0; i < n; ++i) {
            auto it = m.find(creators[i]);
            if (it == end(m)) {
                tmp = max<long>(tmp, views[i]);
                m[creators[i]] = {views[i], views[i], ids[i]};
            } else {
                tmp = max(tmp, get<0>(it->second) += views[i]);
                if (views[i] > get<1>(it->second)) {
                    get<1>(it->second) = views[i];
                    get<2>(it->second) = ids[i];
                } else if (views[i] == get<1>(it->second)) {
                    get<2>(it->second) = min(get<2>(it->second), ids[i]);
                }
            }
        }

        vector<vector<string>> res;
        for (const auto& [creator, v] : m) {
            if (get<0>(v) == tmp) {
                res.push_back({creator, get<2>(v)});
            }
        }

        return res;
    }
};