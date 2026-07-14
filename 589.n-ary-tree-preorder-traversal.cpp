/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    void helper(Node *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;

        arr.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++)
            helper(root->children[i], arr);
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
// @lc code=end
