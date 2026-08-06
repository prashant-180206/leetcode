/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    Node *dfs(Node *root, vector<Node *> &visited)
    {

        if (!root)
            return nullptr;

        if (visited[root->val])
            return visited[root->val];

        Node *clone = new Node(root->val);
        visited[root->val] = clone;

        for (Node *neighbor : root->neighbors)
            clone->neighbors.push_back(dfs(neighbor, visited));

        return clone;
    }

public:
    Node *cloneGraph(Node *node)
    {
        vector<Node *> visited(101, nullptr);
        return dfs(node, visited);
    }
};
// @lc code=end
