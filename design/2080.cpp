#include "include.h"

class RangeFreqQuery {
public:

    unordered_map<int, vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int count = 0;
        if(m.find(value) != m.end()) {
            auto& v = m[value];
            auto left_idx = lower_bound(v.begin(), v.end(), left) - v.begin();
            auto right_idx = upper_bound(v.begin(), v.end(), right) - v.begin();
            return right_idx - left_idx + 1;
        }
        return 0;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */