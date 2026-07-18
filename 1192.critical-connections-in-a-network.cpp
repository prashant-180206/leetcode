/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    int timer = 1;
    vector<int> dt, low;

    void dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, int parent, vector<vector<int>> &cc)
    {
        vis[curr] = true;
        dt[curr] = low[curr] = timer++;

        for (int v : adj[curr])
        {
            if (v == parent)
                continue;
            if (!vis[v])
            {
                dfs(v, adj, vis, curr, cc);
                low[curr] = min(low[curr], low[v]);

                if (low[v] > dt[curr])
                {
                    cc.push_back({curr, v});
                }
            }
            else
            {
                low[curr] = min(low[curr], dt[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> adj(n);
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        timer = 1;
        dt.resize(n);
        low.resize(n);

        vector<bool> vis(n, false);
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis, -1, ans);
        }

        return ans;
    }
};
// @lc code=end
