#include "TreeNode.h"
#include<algorithm>
int dfs(TreeNode* node, bool isLeft) {
    if (!node) return 0;
    if (isLeft) {
        return 1 + dfs(node->left, false);
    } else {
        return 1 + dfs(node->right, true);
    }
}

int longestZigZag(TreeNode* root) {
    if (!root) return 0;
    int leftPath = dfs(root->left, false);
    int rightPath = dfs(root->right, true);
    return std::max(leftPath, rightPath);
}