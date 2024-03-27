#include "include.h"

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto num : arr) {
            m[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it : m) {
            pq.push({it.second, it.first});
        }

        int res = 0;
        int tmp = 0;
        while(!pq.empty()) {
            tmp += pq.top().first;
            pq.pop();
            res++;
            if(tmp >= arr.size() / 2) {
                break;
            }
        }

        return res;
    }
};