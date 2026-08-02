/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
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
class Solution
{
    int sumLeftLeaves(TreeNode *node, bool isLeft)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
        {
            return isLeft ? node->val : 0;
        }
        return sumLeftLeaves(node->left, true) + sumLeftLeaves(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return sumLeftLeaves(root, false);
    }
};
// @lc code=end
