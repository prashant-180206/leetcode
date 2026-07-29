/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = (s[0] != '0');

        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (10 <= two && two <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
// @lc code=end
