#include "include.h"

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int tmp[26] = {0};
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                tmp[words[i][j] - 'a']++;
            }
        }

        int two = 0;
        int one = 0;
        for(int i = 0; i < 26; i++) {
            two += tmp[i] / 2;
            one += tmp[i] % 2;
        }

        int ans = 0;
        sort(words.begin(), words.end(), []
        (const std::string& first, const std::string& second){
            return first.size() < second.size();
        });
        for(int i = 0; i < words.size(); i++) {
            int tmp_two = words[i].size() / 2;
            int tmp_one = words[i].size() % 2;

            // borrow
            if(tmp_one > 0 && one == 0) {
                two--;
                one += 2;
                one--;
            }
            if(two - tmp_two >= 0) {
                ans++;
                two -= tmp_two;
            }
        }

        return ans;
    }
};