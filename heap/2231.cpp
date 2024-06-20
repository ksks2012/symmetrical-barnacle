#include "include.h"

class Solution {
public:
    int largestInteger(int num) {
        string tmp = to_string(num);
        priority_queue<int> pq_odd, pq_even;

        for (char digit : tmp) {
            if ((digit - '0') % 2 == 0) {
                pq_even.push(digit - '0');
            } else {
                pq_odd.push(digit - '0');
            }
        }
        for (char& digit : tmp) {
            if ((digit - '0') % 2 == 0) {
                digit = pq_even.top() + '0';
                pq_even.pop();
            } else {
                digit = pq_odd.top() + '0';
                pq_odd.pop();
            }
        }
        return stoi(tmp);
    }
};