/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */
#include <vector>
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
    vector<TreeNode *> solve(int start, int end)
    {
        if (start > end)
            return {nullptr};

        vector<TreeNode *> ans;

        for (int root = start; root <= end; root++)
        {
            auto left = solve(start, root - 1);
            auto right = solve(root + 1, end);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    auto node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return solve(1, n);
    }
};
// @lc code=end
