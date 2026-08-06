/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include <string>
#include <vector>
using namespace std;

int solve(string s1, string s2, int i, int j, int currlen)
{
    if (i >= s1.length() || j >= s2.length())
        return currlen;

    if (s1[i] == s2[j])
        return solve(s1, s2, i + 1, j + 1, currlen + 1);
    else
        return max(solve(s1, s2, i + 1, j, currlen), solve(s1, s2, i, j + 1, currlen));
}

// @lc code=start
class Solution
{

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[m][n] = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
