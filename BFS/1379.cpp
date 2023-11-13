#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
// Time: O(n), Space: O(n)
class Solution {
public:
    void DFS(TreeNode* cloned, int target, TreeNode **ans) {
        if(cloned == nullptr) {
            return;
        }
        if(cloned->val == target) {
            *ans = cloned;
            return;
        }
        DFS(cloned->left, target, ans);
        DFS(cloned->right, target, ans);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        DFS(cloned, target->val, &ans);
        return ans;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		// check null
		if(original == nullptr)
			return nullptr;

		queue<TreeNode*> q;
		q.push(cloned);

		while (!q.empty())
		{
			int size = q.size();
			// cout << size << endl;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = q.front();
				q.pop();
				if(cur->val == target->val)
					return cur;
				if(cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}

		return nullptr;
    }
};