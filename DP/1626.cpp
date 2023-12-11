#include "include.h"

// DFS
class Solution {
public:
    void zip(
    const vector<int> &a, 
    const vector<int> &b, 
    vector<pair<int,int>> &zipped)  {
        for(size_t i = 0; i < a.size(); ++i) {
            zipped.push_back(make_pair(a[i], b[i]));
        }
    }

    // Write the first and second element of the pairs in 
    // the given zipped vector into a and b. (This assumes 
    // that the vectors have equal length)
    void unzip(
        const vector<pair<int, int>> &zipped, 
        vector<int> &a, 
        vector<int> &b) {
        for(size_t i = 0; i < a.size(); i++) {
            a[i] = zipped[i].first;
            b[i] = zipped[i].second;
        }
    }

    vector<int> scores;
    vector<int> ages;
    int n;

    int DFS(int i, int pre_max) {
        if(i >= n)
            return 0;

        int tmp = 0;
        for(int j = i; j < n; j++) {
            if(scores[j] > pre_max) {
                continue;
            }
            tmp = max(tmp, DFS(j + 1, scores[j]) + scores[j]);
        }
        return tmp;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        this->n = scores.size();

        vector<pair<int,int>> zipped;
        zip(scores, ages, zipped);

        // Sort the vector of pairs
        sort(begin(zipped), end(zipped), 
            [&](const auto& a, const auto& b) {
                if(a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second > b.second;
            });

        // Write the sorted pairs back to the original vectors
        unzip(zipped, scores, ages);

        this->scores = scores;
        this->ages = ages;

        return DFS(0, INT_MAX / 2);
    }
};

// DFS with memory
class Solution {
public:
    void zip(
    const vector<int> &a, 
    const vector<int> &b, 
    vector<pair<int,int>> &zipped)  {
        for(size_t i = 0; i < a.size(); ++i) {
            zipped.push_back(make_pair(a[i], b[i]));
        }
    }

    // Write the first and second element of the pairs in 
    // the given zipped vector into a and b. (This assumes 
    // that the vectors have equal length)
    void unzip(
        const vector<pair<int, int>> &zipped, 
        vector<int> &a, 
        vector<int> &b) {
        for(size_t i = 0; i < a.size(); i++) {
            a[i] = zipped[i].first;
            b[i] = zipped[i].second;
        }
    }

    vector<int> scores;
    vector<int> ages;
    int n;

    int DFS(int i, int prev_age, vector<vector<int>> &memo) {
        if(i >= n)
            return 0;

        int tmp = 0;
        int &res = memo[i][prev_age];
        if(res != -1) {
            return res;
        }
        if(ages[i] < prev_age) {
            tmp = DFS(i + 1, prev_age, memo);
        } else {
            tmp = max(DFS(i + 1, prev_age, memo), DFS(i + 1, ages[i], memo) + scores[i]);
        }
        res = tmp;
        return tmp;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        this->n = scores.size();

        vector<pair<int,int>> zipped;
        zip(ages, scores, zipped);

        // Sort the vector of pairs
        sort(begin(zipped), end(zipped), 
            [&](const auto& a, const auto& b) {
                if(a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });

        // Write the sorted pairs back to the original vectors
        unzip(zipped, ages, scores);

        this->scores = scores;
        this->ages = ages;

        vector<vector<int>> memo(n + 1, vector<int>(1001, -1));

        return DFS(0, 0, memo);
    }
};