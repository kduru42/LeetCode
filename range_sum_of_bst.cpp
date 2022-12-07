#include <iostream>

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode *iter;
        iter = root;
        if (iter == NULL)
            return (0);
        if (iter->val >= low && iter->val <= high)
            total += iter->val;
        rangeSumBST(iter->right, low, high);
        rangeSumBST(iter->left, low, high);
        return (total);
    }
    private:
        int total = 0;
};