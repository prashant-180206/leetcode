/*
 * @lc app=leetcode id=2596 lang=cpp
 *
 * [2596] Check Knight Tour Configuration
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{

public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] != 0)
            return false;


        vector<pair<int, int>> pos(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pos[grid[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < n * n - 1; i++)
        {
            int r1 = pos[i].first;
            int c1 = pos[i].second;
            int r2 = pos[i + 1].first;
            int c2 = pos[i + 1].second;

            int dr = abs(r1 - r2);
            int dc = abs(c1 - c2);

            if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2)))
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
