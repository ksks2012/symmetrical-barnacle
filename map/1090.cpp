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