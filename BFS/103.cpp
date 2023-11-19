
#include "include.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        int layer = 0;
        while (!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if(layer % 2 == 1)
                reverse(begin(tmp), end(tmp));
            ans.push_back(tmp);
            layer++;
        }
        return ans;
    }
};