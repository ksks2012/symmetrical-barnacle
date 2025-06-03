#include "include.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};

        queue<int> studentQueue;
        
        for (int student : students) {
            studentQueue.push(student);
            count[student]++;
        }
        
        int n = sandwiches.size();
        int i;
        for(i = 0; i < n && count[sandwiches[i]] > 0; i++) {
            count[sandwiches[i]]--;
        }

        return n - i;
    }
};