#include "include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        priority_queue<long long> pq;
        while(!q.empty()) {
            long long sum = 0;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                sum += tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            pq.push(sum);
        }
        cout << pq.size() << endl;
        if(pq.size() < k) {
            return -1;
        }

        for(int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};