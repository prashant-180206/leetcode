/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    string preorder(TreeNode *root)
    {
        if (!root)
            return "#";
        auto left = preorder(root->left);
        auto right = preorder(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    TreeNode *buildTree(string &data, int &i)
    {
        if (i >= data.size())
            return nullptr;

        if (data[i] == '#')
        {
            i += 2;
            return nullptr;
        }

        int j = i;
        while (j < data.size() && data[j] != ',')
            j++;
        int val = stoi(data.substr(i, j - i));
        i = j + 1;

        TreeNode *node = new TreeNode(val);
        node->left = buildTree(data, i);
        node->right = buildTree(data, i);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        return preorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int i = 0;
        return buildTree(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
