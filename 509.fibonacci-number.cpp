/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    int solve(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
// @lc code=end
