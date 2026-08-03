/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */
#include <string>
#include <vector>
using namespace std;

void helper(vector<int> &stoneValue, int index, int currentSum, int &maxSum)
{
    if (index >= stoneValue.size())
    {
        maxSum = max(maxSum, currentSum);
        return;
    }

    for (int i = 1; i <= 3; ++i)
    {
        if (index + i <= stoneValue.size())
        {
            int sum = 0;
            for (int j = 0; j < i; ++j)
            {
                sum += stoneValue[index + j];
            }
            helper(stoneValue, index + i, currentSum + sum, maxSum);
        }
    }
}
// @lc code=start
class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int take = 0;

            for (int j = 1; j <= 3 && i + j <= n; ++j)
            {
                take += stoneValue[i + j - 1];
                dp[i] = max(dp[i], take - dp[i + j]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};
// @lc code=end
