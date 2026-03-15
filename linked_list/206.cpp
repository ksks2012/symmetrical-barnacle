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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr, *pre;

        ptr = head;
        pre = nullptr;

        while(ptr != nullptr) {
            ListNode* tmp = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = tmp;
        }
        return pre;
    }
};