#include "include.h"

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size());
        
        vector<pair<int ,int>> qp;
        for (int i = 0; i < queries.size(); i++) {
            qp.push_back({queries[i], i});
        }
        
        sort(qp.begin(), qp.end());
        sort(items.begin(), items.end());
        
        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < qp.size(); i++) {
            int maxi = qp[i].first;
            int idx = qp[i].second;
            
            // Iterate over items, stop when the price exceeds query price or no item left
            while (itemIndex < items.size() && items[itemIndex][0] <= maxi) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            
            res[idx] = maxBeauty;
        }
        
        return res;
    }
};