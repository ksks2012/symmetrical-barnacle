#include "include.h"

// lee
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = searchWord.size();
        vector<vector<string>> ans;

        string cur = "";
        auto it = products.begin();
        for(int i = 0; i < n; i++) {
            cur += searchWord[i];
            vector<string> tmp;
            it = lower_bound(it, products.end(), cur);
            for(int i = 0; i < 3 && it + i != products.end(); i++) {
                string &s = *(it + i);
                if(s.find(cur))
                    break;
                tmp.push_back(s);
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};