/*
 * @lc app=leetcode id=3310 lang=cpp
 *
 * [3310] Remove Methods From Project
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    vector<bool> vis;

    void dfs(int u, vector<vector<int>> &adj)
    {
        vis[u] = true;

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v, adj);
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n);
        vis.assign(n, false);

        // Build graph
        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        dfs(k, adj);

        for (int u = 0; u < n; u++)
        {
            for (int v : adj[u])
            {
                if (!vis[u] && vis[v])
                {
                    vector<int> ans;
                    for (int i = 0; i < n; i++)
                        ans.push_back(i);
                    return ans;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};
// @lc code=end