/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }

        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            ans = max(ans, time);
            q.pop();

            if (i - 1 >= 0 && grid[i - 1][j] == 1 && !vis[i - 1][j]) // top i-1,j
            {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }
            if (i + 1 < n && grid[i + 1][j] == 1 && !vis[i + 1][j]) // bottom i+1,j
            {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }
            if (j + 1 < m && grid[i][j + 1] == 1 && !vis[i][j + 1]) // left i,j+1
            {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1 && !vis[i][j - 1]) // top i-1,j
            {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;

        return ans;
    }
};
// @lc code=end
