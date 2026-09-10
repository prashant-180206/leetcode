/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */
#include <utility>
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
    // rob, skip
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int rob = root->val + l.second + r.second;
        int skip = max(l.first, l.second) + max(r.first, r.second);

        return {rob, skip};
    }

public:
    int rob(TreeNode *root)
    {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
// @lc code=end
