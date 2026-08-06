/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
#include <string>
#include <vector>
using namespace std;

int solve(string s, string t, int i, int j)
{
    if (j == t.length())
        return 1;

    if (i == s.length())
        return 0;

    if (s[i] == t[j])
        return solve(s, t, i + 1, j + 1) + solve(s, t, i + 1, j);
    return solve(s, t, i + 1, j);
}

// @lc code=start
class Solution
{

public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                    dp[j + 1] += dp[j];
            }
        }
        

        return (int)dp[n];
    }
};
// @lc code=end
