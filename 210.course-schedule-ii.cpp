/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{

public:
    vector<int> findOrder(int n, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges)
        {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for (int v : adj[curr])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};
// @lc code=end
