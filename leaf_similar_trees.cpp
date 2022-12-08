#include <iostream>
#include <vector>
using namespace std;

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
    vector <int> &putAllLeafs(TreeNode *root, vector <int> &arr)
    {
        if (!root)
            return arr;
        if (!root->right && !root->left)
            arr.push_back(root->val);
        if (root->right)
            putAllLeafs(root->right, arr);
        if (root->left)
            putAllLeafs(root->left, arr);
        return (arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> arr1;
        vector <int> arr2;
        arr1 = putAllLeafs(root1, arr1);
        arr2 = putAllLeafs(root2, arr2);
        if (arr1.size() != arr2.size())
            return (false);
        for (int i = 0; i < arr1.size(); i++)
            if (arr1[i] != arr2[i])
                return (false);
        return (true);
    }
};