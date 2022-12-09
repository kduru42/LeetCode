#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findOneDiff(TreeNode *root, TreeNode *iter)
    {
        if (!iter)
            return (max);
        if (iter->right && abs(root->val - iter->right->val) > max)
            max = abs(root->val - iter->right->val);
        if (iter->left && abs(root->val - iter->left->val) > max)
            max = abs(root->val - iter->left->val);
        findOneDiff(root, iter->right);
        findOneDiff(root, iter->left);
        return (max);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return (max);
        iter = root;
        max = findOneDiff(root, iter);
        if (root->right)
            maxAncestorDiff(root->right);
        if (root->left)
            maxAncestorDiff(root->left);
        return (max);
    }
private:
    int max = -1;
    TreeNode *iter;
};