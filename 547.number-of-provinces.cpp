/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{

    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[i] = true;
        for (int j = 0; j < adj.size(); j++)
            if (adj[i][j] == 1 && !vis[j])
                dfs(j, adj, vis);
    }

public:
    int findCircleNum(vector<vector<int>> &adj)
    {
        int n = adj.size();
        int count = 0;

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                count++;
            }
        }

        return count;
    }
};
// @lc code=end
