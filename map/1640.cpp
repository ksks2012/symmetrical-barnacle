#include "include.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> m;
        int n = pieces.size();

        for(int i = 0; i < n; i++) {
            m[pieces[i][0]] = i;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(m.find(arr[i]) == m.end()) {
                return false;
            }
            int idx = m[arr[i]];
            for(int j = 0; j < pieces[idx].size(); j++) {
                if(arr[i] != pieces[idx][j]) {
                    return false;
                }
                i++;
            }
            i--;
        }

        return true;
    }
};