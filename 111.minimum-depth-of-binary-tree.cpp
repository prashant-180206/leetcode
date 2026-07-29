/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */
#include <limits>
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
    int mindepth = INT_MAX;

    void dfs(TreeNode *root, int depth)
    {
        if (!root->left && !root->right)
        {
            mindepth = min(mindepth, depth);
        }
        if (root->left)
            dfs(root->left, depth + 1);
        if (root->right)
            dfs(root->right, depth + 1);
    }

public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
            
        dfs(root, 1);
        return mindepth;
    }
};
// @lc code=end
