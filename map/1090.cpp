#include "include.h"

class Solution {
public:
    void zip(
        const std::vector<int> &a, 
        const std::vector<int> &b, 
        std::vector<std::pair<int,int>> &zipped)
        {
            for(size_t i=0; i<a.size(); ++i)
            {
                zipped.push_back(std::make_pair(a[i], b[i]));
            }
        }

    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        map<int, int> tmp;
        int n = values.size();

        for(int i = 0; i < n; i++) {
            tmp[labels[i]] = 0;
        }
        
        vector<pair<int, int>> zipped;
        zip(values, labels, zipped);

        std::sort(std::begin(zipped), std::end(zipped), 
        [&](const auto& a, const auto& b)
        {
            return a.first > b.first;
        });

        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            // cout << zipped[i].first << endl;
            if(count < numWanted && tmp[zipped[i].second] < useLimit) {
                count++;
                sum += zipped[i].first;
                tmp[zipped[i].second]++;
            } else if (count == numWanted) {
                break;
            }
        }

        return sum;
    }
};

// optimal solution
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> zipped;
        for (int i = 0; i < n; ++i)
            zipped.emplace_back(values[i], labels[i]);

        sort(zipped.begin(), zipped.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        unordered_map<int, int> label_used;
        int count = 0, sum = 0;

        for (auto& p : zipped) {
            int val = p.first, label = p.second;
            if (label_used[label] < useLimit) {
                sum += val;
                label_used[label]++;
                count++;
                if (count == numWanted)
                    break;
            }
        }

        return sum;
    }
};

// Greedy
class Solution {
public:    
    int largestValsFromLabels(vector<int>& vs, vector<int>& ls, int wanted, int limit, int res = 0) {
        multimap<int, int> mm;
        unordered_map<int, int> mp;
        for (auto i = 0; i < vs.size(); ++i) 
            mm.insert({vs[i], ls[i]});
        for (auto it = rbegin(mm); it != rend(mm) && wanted > 0; ++it) {
            if (++mp[it->second] <= limit) {
                res += it->first;
                --wanted;
            }
        }
        return res;
    }
};
