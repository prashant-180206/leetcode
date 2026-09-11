/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */
#include <vector>
#include <climits>
using namespace std;

// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins)
        {
            for (int i = c; i <= amount; i++)
            {
                dp[i] += dp[i - c];
            }
        }

        return dp[amount];
    }
};
// @lc code=end
