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