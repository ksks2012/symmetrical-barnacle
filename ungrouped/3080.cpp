#include "include.h"

// TLE
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> res;
        vector<int> marked(nums.size(), 0);

        for(int i = 0; i < queries.size(); i++) {
            int count = queries[i][1];
            marked[queries[i][0]] = 1;

            long long tmp = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(int j = 0; j < nums.size(); j++) {
                if(marked[j] == 0) {
                    tmp += nums[j];
                    pq.push(make_pair(nums[j], j));
                }
            }
            count = min(count, int(pq.size()));
            for(int j = 0; j < count; j++) {
                tmp -= pq.top().first;
                marked[pq.top().second] = 1;
                pq.pop();
            }
            res.push_back(tmp);
        }

        return res;
    }
};

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long n = nums.size();
        vector<long long> res;
        unordered_set<long long> st;
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;  

        for (long long i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long sum = accumulate(nums.begin(), nums.end(), 0LL);  

        for (auto& it : queries) {
            long long idx = it[0];
            long long k = it[1];

            // idx has not marked before            
            if (st.find(idx) == st.end()) {
                st.insert(idx);
                sum -= nums[idx];
            }

            // remove k unmarked elements
            while(k > 0 && !pq.empty()){
                long long val = pq.top().first;
                long long idx2 = pq.top().second;
                pq.pop();
                
                if(st.find(idx2) == st.end()){
                    st.insert(idx2);
                    // Prefix Sum
                    sum -= val;
                    k--;
                }
            }

            res.push_back(sum);
        }

        return res;
    }
};

// endlesscheng
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        ranges::stable_sort(ids, [&](int i, int j) { 
            return nums[i] < nums[j]; 
        });

        vector<long long> ans;
        int j = 0;
        for (auto &q : queries) {
            int i = q[0], k = q[1];
            s -= nums[i];
            nums[i] = 0; // mark
            for (; j < n && k; j++) {
                i = ids[j];
                if (nums[i] > 0) { // do not marked
                    s -= nums[i];
                    nums[i] = 0;
                    k--;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};