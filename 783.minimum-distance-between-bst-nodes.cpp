/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    TreeNode *prev = nullptr;

public:
    int minDiffInBST(TreeNode *root)
    {
        if (root == nullptr)
            return INT_MAX;

        int ans = INT_MAX;
        if (root->left != nullptr)
        {
            int lmin = minDiffInBST(root->left);
            ans = min(ans, lmin);
        }
        if (prev != nullptr)
            ans = min(ans, root->val - prev->val);
        prev = root;

        if (root->right != nullptr)
        {
            int lmin = minDiffInBST(root->right);
            ans = min(ans, lmin);
        }
        return ans;
    }
};
// @lc code=end
