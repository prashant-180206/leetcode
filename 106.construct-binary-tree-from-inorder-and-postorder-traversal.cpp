/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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

    int search(vector<int> &in, int start, int end, int val)
    {
        for (int i = start; i <= end; i++)
        {
            if (in[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode *build(vector<int> &in, vector<int> &post, int start, int end, int &postIdx)
    {
        if (start > end)
            return nullptr;

        int rootVal = post[postIdx--];

        int idx = search(in, start, end, rootVal);

        TreeNode *root = new TreeNode(rootVal);

        root->right = build(in, post, idx + 1, end, postIdx);
        root->left = build(in, post, start, idx - 1, postIdx);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postIdx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIdx);
    }
};
// @lc code=end
