/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 */

#include <climits>
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
    int first = -1;
    long long second = LLONG_MAX;

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        int val = root->val;
        if (val != first && val < second)
        {
            second = val;
        }
        dfs(root->left);
        dfs(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        first = root->val;
        dfs(root);
        return second == LLONG_MAX ? -1 : second;
    }
};
// @lc code=end
