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

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ranges::sort(items, {}, [](auto& item) { return item[0]; });
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        for (int& q : queries) {
            int j = ranges::upper_bound(items, q, {}, [](auto& item) { return item[0]; }) - items.begin();
            q = j ? items[j - 1][1] : 0;
        }
        return queries;
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ranges::sort(items, {}, [](auto& item) { return item[0]; });
        int k = 0;
        for (int i = 1; i < items.size(); i++) {
            if (items[i][1] > items[k][1]) { // useful
                items[++k] = items[i];
            }
        }

        for (int& q : queries) {
            int j = upper_bound(items.begin(), items.begin() + (k + 1), q, [](int value, auto& item) {
                return value < item[0];
            }) - items.begin();
            q = j ? items[j - 1][1] : 0;
        }
        return queries;
    }
};