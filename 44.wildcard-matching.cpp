/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include <string>
#include <vector>
using namespace std;

bool helper(string &s, string &p, int i, int j)
{
    if (j == p.length())
        return i == s.length();
    if (i == s.length())
    {
        for (int k = j; k < p.length(); k++)
            if (p[k] != '*')
                return false;
        return true;
    }

    if (p[j] == '?' || p[j] == s[i])
    {
        return helper(s, p, i + 1, j + 1);
    }
    else if (p[j] == '*')
    {
        return helper(s, p, i, j + 1) || helper(s, p, i + 1, j);
    }
    return false;
}
// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;

        for (int j = n - 1; j >= 0; j--)
            dp[m][j] = (p[j] == '*') && dp[m][j + 1];

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (p[j] == '?' || p[j] == s[i])
                    dp[i][j] = dp[i + 1][j + 1];
                else if (p[j] == '*')
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                else
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
