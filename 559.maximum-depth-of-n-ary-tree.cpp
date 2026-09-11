/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

#include <vector>
#include <queue>
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
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;

            
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        int levels = 1;

        while (!q.empty())
        {
            auto val = q.front();
            q.pop();

            if (val == nullptr)
            {
                if (!q.empty())
                {
                    levels++;
                    q.push(nullptr);
                }
            }
            else
            {
                for (auto c : val->children)
                {
                    q.push(c);
                }
            }
        }
        return levels;
    }
};
// @lc code=end
