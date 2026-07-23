/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        const int NEG = -1e9;

        // dp[i][j] = max cherries when
        // person1 is at (i, k-i)
        // person2 is at (j, k-j)
        vector<vector<int>> dp(n, vector<int>(n, NEG));
        dp[0][0] = grid[0][0];

        for (int k = 1; k <= 2 * (n - 1); k++)
        {
            vector<vector<int>> ndp(n, vector<int>(n, NEG));

            for (int i1 = max(0, k - (n - 1)); i1 <= min(n - 1, k); i1++)
            {
                int j1 = k - i1;
                if (j1 >= n || grid[i1][j1] == -1)
                    continue;

                for (int i2 = max(0, k - (n - 1)); i2 <= min(n - 1, k); i2++)
                {
                    int j2 = k - i2;
                    if (j2 >= n || grid[i2][j2] == -1)
                        continue;

                    int best = NEG;

                    // both came from up
                    if (i1 > 0 && i2 > 0)
                        best = max(best, dp[i1 - 1][i2 - 1]);

                    // first up, second left
                    if (i1 > 0)
                        best = max(best, dp[i1 - 1][i2]);

                    // first left, second up
                    if (i2 > 0)
                        best = max(best, dp[i1][i2 - 1]);

                    // both came from left
                    best = max(best, dp[i1][i2]);

                    if (best == NEG)
                        continue;

                    int cherries = grid[i1][j1];

                    // Don't count twice if both are on the same cell
                    if (i1 != i2)
                        cherries += grid[i2][j2];

                    ndp[i1][i2] = best + cherries;
                }
            }

            dp = move(ndp);
        }

        return max(0, dp[n - 1][n - 1]);
    }
};
// @lc code=end
