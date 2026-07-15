/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{

    bool hasCycleDFS(int curr, vector<bool> &vis, vector<bool> &recpath, vector<vector<int>> &edges)
    {
        vis[curr] = true;
        recpath[curr] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][1];
            int v = edges[i][0];

            if (u == curr)
            {
                if (!vis[v])
                {
                    if (hasCycleDFS(v, vis, recpath, edges))
                    {
                        return true;
                    }
                }
                else if (recpath[v])
                {
                    return true;
                }
            }
        }
        recpath[curr] = false;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>> &edges)
    {
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);

        for (int i = 0; i < n; i++)
            if (!vis[i])
                if (hasCycleDFS(i, vis, recpath, edges))
                    return false;

        return true;
    }
};
// @lc code=end
