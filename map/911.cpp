#include "../include.h"

class TopVotedCandidate {
public:
    unordered_map<int, int> m;
    vector<int> times;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = persons.size(), lead = -1;
        this->times = times;
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            count[persons[i]]++;
            // update the current lead of votes for each time point
            if(count[persons[i]] >= count[lead]) {
                lead = persons[i];
            }
            m[times[i]] = lead;
        }
    }

    int q(int t) {
        int key = *--upper_bound(times.begin(), times.end(), t);
        return m[key];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

