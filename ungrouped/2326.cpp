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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        if (!head) return res;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (head && top <= bottom && left <= right) {
            for (int col = left; col <= right && head; ++col) {
                res[top][col] = head->val;
                head = head->next;
            }
            ++top;

            for (int row = top; row <= bottom && head; ++row) {
                res[row][right] = head->val;
                head = head->next;
            }
            --right;

            if (top <= bottom) {
                for (int col = right; col >= left && head; --col) {
                    res[bottom][col] = head->val;
                    head = head->next;
                }
                --bottom;
            }

            if (left <= right) {
                for (int row = bottom; row >= top && head; --row) {
                    res[row][left] = head->val;
                    head = head->next;
                }
                ++left;
            }
        }

        return res;
    }
};