/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// recursive approach
// class Solution
// {
//     void helper(TreeNode *root, vector<int> &arr)
//     {
//         if (root == nullptr)
//             return;
//         helper(root->left, arr);
//         arr.push_back(root->val);
//         helper(root->right, arr);
//     }

// public:
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         helper(root, result);
//         return result;
//     }
// };
// @lc code=start

//  morris inorder traversal
class Solution
{

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            if (curr->left == nullptr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // find inorder predessesor
                TreeNode *ip = curr->left;
                while (ip->right != nullptr && ip->right != curr)
                {
                    ip = ip->right;
                }

                if (ip->right == nullptr)
                {
                    ip->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ip->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
