/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> nextr(n, INT_MAX);

        for (int j = 0; j < n; j++)
            nextr[j] = arr[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                int m = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (k == j)
                        continue;
                    m = min(m, nextr[k]);
                }
                curr[j] = m + arr[i][j];
            }
            nextr = curr;
        }
        int m = INT_MAX;
        for (int i : nextr)
            m = min(m, i);

        return m;
    }
};
// @lc code=end
