/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include <vector>
#include <string>
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
    void buildpaths(TreeNode *root, string path, vector<string> &ans)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }

        if (root->left)
            buildpaths(root->left, path + "->" + to_string(root->left->val), ans);
        if (root->right)
            buildpaths(root->right, path + "->" + to_string(root->right->val), ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string path = to_string(root->val);
        buildpaths(root, path, ans);
        return ans;
    }
};
// @lc code=end
