/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{

public:
    bool predictTheWinner(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[i][i] = arr[i];

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end
