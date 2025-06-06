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

class Solution {
public:
    ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
        while (cur != nullptr) {
            swap(cur->next, prev);
            swap(prev != nullptr ? prev->next : prev, cur);
        }
        return prev;
    }    

    int pairSum(ListNode* head) {
        int res = 0;
        auto slow = head, fast = head;
        // find the middle of the list
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverseList(slow);
        while (slow != nullptr) {
            res = max(res, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }
        return res;
    }
};

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