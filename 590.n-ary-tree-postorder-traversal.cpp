/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
        for (Node *child : root->children)
            helper(child, arr);
        arr.push_back(root->val);
    }

public:
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
// @lc code=end
