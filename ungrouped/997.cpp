#include "../include.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1)
            return 1;
		map<int, int> m, p;

		for (int i = 0; i < trust.size(); i++) {
            p[trust[i][0]]++;
			m[trust[i][1]]++;
		}

		for (auto i: m) {
			if (i.second == n - 1 && p.count(i.first) == 0)
				return i.first;
		}
		return -1;
    }
};