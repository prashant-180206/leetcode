/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    int diffhelper(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return arr[start];
        int lft = arr[start] - diffhelper(arr, start + 1, end);
        int rgt = arr[end] - diffhelper(arr, start, end - 1);
        return max(lft, rgt);
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        for (int len = 2; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;
                dp[start][end] = max(piles[start] - dp[start + 1][end], piles[end] - dp[start][end - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }
};
// @lc code=end
