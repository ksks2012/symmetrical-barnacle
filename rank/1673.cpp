#include "../include.h"

// stack
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        stack<int> s;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.top() > nums[i] && s.size() + n - i > k) {
                s.pop();
            }
            if(s.size() < k) {
                s.push(nums[i]);
            }
        }
        
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// heap
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int len = n - k;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		// first sliding window wiht N-k+1 elements
        for (int i = 0; i <= len; i++) {
            pq.push({nums[i], i});
        }
        pair<int, int> t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int min_idx = t.second;
        for (int i = len + 1; i < n; i++) { // rest of the sliding windows with one new element added at a time and ignoring the elements already selected and elements before them
            pq.push({nums[i], i});
            t = pq.top();
            while (t.second < min_idx) { // ignore min elements before current min element index
                pq.pop();
                t = pq.top();
            }
            pq.pop();
			// new minimum element from the current sliding window
            res.push_back(t.first);
            min_idx = t.second;
        }
        return res;
    }
};