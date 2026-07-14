/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        // check if p or q is lca itself
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *llca = lowestCommonAncestor(root->left, p, q);
        TreeNode *rlca = lowestCommonAncestor(root->right, p, q);

        if (llca && rlca)
            return root;
        else if (llca != nullptr)
            return llca;
        else
            return rlca;
    }
};
// @lc code=end
