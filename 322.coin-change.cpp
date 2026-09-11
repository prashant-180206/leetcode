/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &arr, int targ)
{
    if (targ == 0)
        return 0;
    if (targ < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i : arr)
    {
        int ans = solve(arr, targ - i);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
            for (int c : coins)
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c] + 1);

        if (dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
};
// @lc code=end
