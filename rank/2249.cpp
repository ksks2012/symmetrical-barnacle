#include "include.h"

// lee
class Solution {
public:
    int countLatticePoints(vector<vector<int>> circles) {
        unordered_set<int> res;
        for (auto& c : circles) {
            // from x - r to x + r
            for (int i = -c[2]; i <= c[2]; i++) {
                // from y - r to y + r
                for (int j = -c[2]; j <= c[2]; j++) {
                    // 0 ~ 1000: y
                    // 1000 ~ 2000: x
                    if (i * i + j * j <= c[2] * c[2]) {
                        cout << (c[0] + i) * 1000 << " " << c[1] + j << endl;
                        res.insert((c[0] + i) * 1000 + c[1] + j);
                    }    
                }      
            }           
        }
            
        return res.size();
    }
};