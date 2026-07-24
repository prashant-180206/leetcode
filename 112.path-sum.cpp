/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool helper(TreeNode *root, int currSum, int target)
    {
        if (!root)
            return false;

        currSum += root->val;

        if (!root->left && !root->right)
            return currSum == target;

        return helper(root->left, currSum, target) ||
               helper(root->right, currSum, target);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return helper(root, 0, targetSum);
    }
};
// @lc code=end
