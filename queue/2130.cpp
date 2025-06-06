#include "../include.h"

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode*ptr = head;
        while(ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int max = 0;
        int n = v.size();
        for(int i = 0; i < v.size() / 2; i++) {
            if(v[i] + v[n - i - 1] > max)
                max = v[i] + v[n - i - 1];
        }
        return max;
    }
};