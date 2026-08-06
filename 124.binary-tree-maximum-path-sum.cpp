/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
#include <climits>
#include <algorithm>
using namespace std;

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
    int maxSum = INT_MIN;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxSum;
    }
};
// @lc code=end
