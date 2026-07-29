/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sum = 0;
    void dfs(TreeNode *root, int currnum)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            sum += (currnum * 10 + root->val);
            return;
        }
        dfs(root->left, currnum * 10 + root->val);
        dfs(root->right, currnum * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return sum;
    }
};
// @lc code=end
