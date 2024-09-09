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
    vector<int> way = {0, 1, 0, -1, 0};
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int max_x = m - 1;
        int max_y = n - 1;
        int min_x = 0;
        int min_y = 0;

        vector<vector<int>> res(m, vector<int>(n, -1));

        while (head) {
            for (int col = min_y; col <= max_y && head; ++col) {
                res[min_x][col] = head->val;
                head = head->next;
            }
            min_x++;
            
            for (int row = min_x; row <= max_x && head; ++row) {
                res[row][max_y] = head->val;
                head = head->next;
            }
            max_y--;
            
            for (int col = max_y; col >= min_y && head; --col) {
                res[max_x][col] = head->val;
                head = head->next;
            }
            max_x--;
            
            for (int row = max_x; row >= min_x && head; --row) {
                res[row][min_y] = head->val;
                head = head->next;
            }
            min_y++;
        }
        return res;
    }
};