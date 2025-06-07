#include "../include.h"

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
    ListNode* doubleIt(ListNode* head) {
        ListNode *ptr = head->next;
        ListNode *pre = head;

        if (head->val * 2 >= 10) {
            head->val = head->val * 2 % 10;
            ListNode *new_node = new ListNode(1);
            new_node->next = head;
            head = new_node;
        } else {
            head->val = head->val * 2 % 10;
        }
        
        while(ptr != NULL) {
            int tmp = ptr->val * 2;
            if(tmp >= 10) {
                pre->val += tmp / 10;
            }
            ptr->val = tmp % 10;
            ptr = ptr->next;
            pre = pre->next;
        }   
        return head;
    }
};