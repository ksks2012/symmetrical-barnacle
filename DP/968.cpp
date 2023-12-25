#include "include.h"

// endlesscheng
class Solution {
    tuple<int, int, int> DFS(TreeNode *node) {
        if(node == nullptr)
            return {INT_MAX / 2, 0, 0};

        auto [l_choose, l_by_parent, l_by_children] = DFS(node->left);
        auto [r_choose, r_by_parent, r_by_children] = DFS(node->right);
        int choose = min(l_choose, l_by_parent) + min(r_choose, r_by_parent) + 1;
        int by_parent = min(l_choose, l_by_children) + min(r_choose, r_by_children);
        int by_children = min({l_choose + r_by_children, l_by_children + r_choose, l_choose + r_choose});
        return {choose, by_parent, by_children};
    }

public:
    int minCameraCover(TreeNode *root) {
        auto [choose, _, by_children] = DFS(root);
        return min(choose, by_children);
    }
};