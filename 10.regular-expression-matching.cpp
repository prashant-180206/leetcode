/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>
#include <vector>
using namespace std;

bool helper(string s, string p, int i, int j)
{
    if (j == p.size())
        return i == s.size();

    bool firstMatch =
        (i < s.size()) &&
        (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*')
        return helper(s, p, i, j + 2) ||
               (firstMatch && helper(s, p, i + 1, j));

    return firstMatch && helper(s, p, i + 1, j + 1);
}
// @lc code=start
class Solution
{

public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                bool firstMatch = (i < m) && (s[i] == p[j] || p[j] == '.');
                if (p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                else
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
