#include "../include.h"

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<int> idx(n, -1);
        for(int i = 0; i < indices.size(); i++) {
            int j = 0;
            while(j < sources[i].size() && indices[i] + j < n && s[indices[i] + j] == sources[i][j]) {
                j++;
            }
            if(j == sources[i].size()) {
                for(int k = 0; k < sources[i].size(); k++) {
                    idx[indices[i] + k] = i;
                }
            }
        }

        string res = "";
        for(int i = 0; i < n; i++) {
            if(idx[i] == -1) {
                res += s[i];
            } else {
                res += targets[idx[i]];
                i += sources[idx[i]].size() - 1;
            }
        }

        return res;
    }
};

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> v;
        for (int i = 0; i < indexes.size(); ++i) {
            v.push_back({indexes[i], i});
        }
        sort(v.rbegin(), v.rend());
        for (auto a : v) {
            int i = a.first;
            string s = sources[a.second], t = targets[a.second];
            if (S.substr(i, s.size()) == s) {
                S = S.substr(0, i) + t + S.substr(i + s.size());
            }
        }
        return S;
    }
};