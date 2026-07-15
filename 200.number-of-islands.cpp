/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis, int m, int n)
    {

        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == '0')
            return;
        vis[i][j] = true;

        dfs(i, j + 1, grid, vis, m, n);
        dfs(i, j - 1, grid, vis, m, n);
        dfs(i - 1, j, grid, vis, m, n);
        dfs(i + 1, j, grid, vis, m, n);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, vis, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
};
// @lc code=end
