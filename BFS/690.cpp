#include "../include.h"

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        vector<int> sub;
        map<int, Employee*> m;
        for(auto e : employees) {
            m[e->id] = e;
            if(e->id == id) {
                sub = e->subordinates;
                ans = e->importance;
            }
        }

        queue<int> q;
        for(int i = 0; i < sub.size(); i++) {
            q.push(sub[i]);
        }

        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                int top = q.front();
                q.pop();
                ans += m[top]->importance;
                for(int i = 0; i < m[top]->subordinates.size(); i++) {
                    q.push(m[top]->subordinates[i]);
                }
            } 
        }

        return ans;
    }
};