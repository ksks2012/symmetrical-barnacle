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

// Stack optimization
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode tmp(INT_MAX);
        vector<ListNode*> st{ &tmp };
        for (auto p = head; p != nullptr; p = p->next) {
            while (st.back()->val < p->val) 
                st.pop_back();
            st.back()->next = p;
            st.push_back(p);
        }
        return tmp.next;
    }
};

// Reverse
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            swap(cur->next, prev);
            swap(prev, cur);
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        for (auto p = head; p != nullptr && p->next != nullptr; ) {
            if (p->val > p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return reverseList(head);
    }
};