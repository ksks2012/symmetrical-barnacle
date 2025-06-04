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


// simulation
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students) {
            q.push(s);
        }

        int index = 0;             // pointer for sandwiches
        int tries = 0;         

        while (!q.empty() && tries < q.size()) {
            if (q.front() == sandwiches[index]) {
                // Student eats, remove from queue, move to next sandwich
                q.pop();
                index++;
                tries = 0; // Reset tries counter
            } else {
                // Student refuses, move to back of queue
                q.push(q.front());
                q.pop();
                tries++; // Record one refusal
            }
        }

        return q.size(); // Number of students who couldn't eat
    }
};
