#include "include.h"

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(), dictionary.end());
        string word, res;
        stringstream ss(sentence);
        while(ss >> word) {
            string str;
            bool flag = false;
            for(char ch : word) {
                str += ch;
                if(st.count(str)) {
                    flag = true;
                    break;
                }
            }
            res += (flag ? str : word);
            res += " ";
        }
        res.pop_back();
        return res;
    }
};