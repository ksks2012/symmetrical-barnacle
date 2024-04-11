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
    ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        ListNode *ptr = head;
        while(ptr != nullptr) {
            while(!st.empty() && st.back() < ptr->val) {
                st.pop_back();
            }
            st.push_back(ptr->val);
            ptr = ptr->next;
        }

        ListNode *res = new ListNode(-1, nullptr);
        ptr = res;
        for(auto s : st) {
            ptr->next = new ListNode(s, nullptr);
            ptr = ptr->next;
        }
        
        return res->next;
    }
};

// lee
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) 
            return NULL;
        head->next = removeNodes(head->next);
        return head->next && head->val < head->next->val ?  head->next : head;
    }
};
