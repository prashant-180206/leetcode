/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {

            if (!dp[i])
                continue;

            for (string &word : wordDict)
            {

                int len = word.size();

                if (i + len <= n && s.compare(i, len, word) == 0)
                    dp[i + len] = true;
            }
        }

        return dp[n];
    }
};
// @lc code=end
