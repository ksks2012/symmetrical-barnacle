#include "include.h"

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        int max_count = 0;
        for(auto c : s) {
            max_count = max(max_count, ++m[c]);
        }

        vector<vector<int>> bucket(max_count + 1);
        for(const auto &p : m) {
            bucket[p.second].push_back(p.first);
        }

        string ans;
        for(int i = max_count; i >= 0; i--) {
            for(auto c : bucket[i]) {
                ans.append(m[c], c);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;

        for(auto c: s) {
            m[c]++;
        }

        for(auto it: m) {
            pq.push({it.second, it.first});
        }

        string res = "";
        while(!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << endl;
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};