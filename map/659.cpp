#include "include.h"

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num : nums) 
            ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) 
                continue;

            if (need[num] > 0) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else 
                return false;
            --freq[num];
        }
        return true;
    }
};

typedef pair<int,int>PII;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        int n = nums.size();
        pq.push({nums[0],1});

        for(int i = 1; i < n; i++) {
            int tmp = nums[i];
            while(!pq.empty()) {
                PII t = pq.top();
                if(t.first < tmp - 1) {
                    if(t.second < 3) return false;
                    else pq.pop();
                } else break;
            }
            if(pq.empty() || pq.top().first > tmp - 1) pq.push({tmp,1});
            else {
                PII t = pq.top(); pq.pop();
                pq.push({t.first + 1, t.second + 1});
            }
        }

        while(!pq.empty()) {
            PII t = pq.top(); pq.pop();
            if(t.second < 3) return false;
        }

        return true;   
    }
};