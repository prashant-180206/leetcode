/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int ans = 0;

    void dfs(TreeNode *root, int val)
    {
        if (!root)
            return;

        val = val * 2 + root->val;

        if (!root->left && !root->right)
        {
            ans += val;
            return;
        }

        dfs(root->left, val);
        dfs(root->right, val);
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};

// @lc code=end
