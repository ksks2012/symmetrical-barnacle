#include "include.h"

//endlesscheng
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int, int>; // Frequency, element value
        // L: maximum elements with frequency > x
        // R: other elements
        set<pii> L, R;

        long long sum_l = 0; // Sum of elements in L
        unordered_map<int, int> cnt;

        // insert number by frequency
        auto add = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            if (!L.empty() && p > *L.begin()) { // p is greater than the smallest in L
                sum_l += (long long) p.first * p.second;
                L.insert(p);
            } else {
                R.insert(p);
            }
        };

        // remove old frequency
        auto del = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            auto it = L.find(p);
            if (it != L.end()) {
                sum_l -= (long long) p.first * p.second;
                L.erase(it);
            } else {
                R.erase(p);
            }
        };

        // Balance the two sets
        auto l2r = [&]() {
            pii p = *L.begin();
            sum_l -= (long long) p.first * p.second;
            L.erase(p);
            R.insert(p);
        };
        auto r2l = [&]() {
            pii p = *R.rbegin();
            sum_l += (long long) p.first * p.second;
            R.erase(p);
            L.insert(p);
        };

        vector<int> res(nums.size() - k + 1);
        for (int r = 0; r < nums.size(); r++) {
            // Add in
            int in = nums[r];
            del(in);
            cnt[in]++;
            add(in);

            int l = r + 1 - k;
            if (l < 0) {
                continue;
            }

            // Maintain size
            while (!R.empty() && L.size() < x) {
                r2l();
            }
            while (L.size() > x) {
                l2r();
            }
            res[l] = sum_l;

            // Remove out
            int out = nums[l];
            del(out);
            cnt[out]--;
            add(out);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> freq;

        // Initialize frequency map for the first window
        for (int j = 0; j < k; j++) {
            freq[nums[j]]++;
        }

        // Calculate x-sum for the first window
        res.push_back(calculateXSum(freq, x));

        // Slide the window
        for (int i = 1; i <= n - k; i++) {
            // Remove the element going out of the window
            freq[nums[i - 1]]--;
            if (freq[nums[i - 1]] == 0) {
                freq.erase(nums[i - 1]);
            }

            // Add the new element coming into the window
            freq[nums[i + k - 1]]++;

            // Calculate x-sum for the current window
            res.push_back(calculateXSum(freq, x));
        }
        
        return res;
    }

private:
    int calculateXSum(const unordered_map<int, int>& freq, int x) {
        // Use a priority queue (max heap) to get the top x elements
        priority_queue<pair<int, int>> pq; // (frequency, value)

        for (const auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }

        int sum = 0;
        for (int i = 0; i < x && !pq.empty(); i++) {
            auto top = pq.top();
            pq.pop();
            sum += top.second * top.first; // sum = value * frequency
        }

        return sum;
    }
};