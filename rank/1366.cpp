#include "include.h"

# define PCV pair<char, vector<int>>
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        int n = votes[0].size();
        unordered_map<char, vector<int>> ranking;
        for (char vid: votes[0]) {
            ranking[vid].resize(n);
        }

        for (auto & vote: votes) {
            for (int i = 0; i < vote.size(); ++i) {
                ++ranking[vote[i]][i];
            }
        }
        
        vector<PCV> result(ranking.begin(), ranking.end());
        sort(result.begin(), result.end(), [](const PCV& l, const PCV& r) {
            return l.second > r.second || (l.second == r.second && l.first < r.first);
        });
        string ans;
        for (auto& [vid, rank]: result) {
            ans += vid;
        }
        return ans;
    }
};
