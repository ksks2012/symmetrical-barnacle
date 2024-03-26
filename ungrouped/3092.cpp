#include "include.h"

// endlesscheng
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, long long> m;
        priority_queue<pair<long long, int>> pq;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            m[x] += freq[i];
            // {freq, nums}
            pq.emplace(m[x], x);
            // top of heap has changed
            while (pq.top().first != m[pq.top().second]) {
                // delete
                pq.pop();
            }
            res[i] = pq.top().first;
        }
        return res;
    }
};

// hash table + multiset
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
        unordered_map<int, long long> m;
        multiset<long long> s;
        int n = nums.size();
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            auto it = s.find(m[x]);
            if (it != s.end()) {
                s.erase(it);
            }
            m[x] += freq[i];
            s.insert(m[x]);
            res[i] = *s.rbegin();
        }
        return res;
    }
};