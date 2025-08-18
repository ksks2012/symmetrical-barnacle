#include "../include.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res = 0;

        unordered_set<string> uniqueEmails;

        for (const string& email : emails) {
            string local = email.substr(0, email.find('@'));
            string domain = email.substr(email.find('@'));

            // Remove dots from local part
            local.erase(remove(local.begin(), local.end(), '.'), local.end());

            // Remove everything after the first plus sign
            local = local.substr(0, local.find('+'));

            uniqueEmails.insert(local + domain);
        }

        return uniqueEmails.size();
    }
};