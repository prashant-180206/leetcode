/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int order = 0;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
            return -1;

        if (root->left != nullptr)
        {
            int lans = kthSmallest(root->left, k);
            if (lans != -1)
                return lans;
        }
        if (order + 1 == k)
            return root->val;
        order++;
        if (root->right != nullptr)
        {
            int rans = kthSmallest(root->right, k);
            if (rans != -1)
                return rans;
        }

        return -1;
    }
};
// @lc code=end
