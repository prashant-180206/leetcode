/*
 * @lc app=leetcode id=2265 lang=cpp
 *
 * [2265] Count Nodes Equal to Average of Subtree
 */
#include <utility>
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
    int ans = 0;
    // sum , count
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int cnt = l.second + r.second + 1;
        int sum = l.first + r.first + root->val;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
