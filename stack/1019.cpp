#include "include.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;

        vector<pair<int, int>> st;
        ListNode *tmp = head;
        int count = 0;
        while(tmp != NULL) {
            while(!st.empty() && st.back().first < tmp->val) {
                res[st.back().second] = tmp->val;
                st.pop_back();
            }
            st.push_back({tmp->val, count});
            res.push_back(tmp->val);
            count++;
            tmp = tmp->next;
        }
        while(!st.empty()) {
            res[st.back().second] = 0;
            st.pop_back();
        }

        return res;
    }
};