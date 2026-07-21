/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++)
        {
            for (int root = 1; root <= nodes; root++)
            {
                int left = root - 1;
                int right = nodes - root;

                dp[nodes] += dp[left] * dp[right];
            }
        }

        return dp[n];
    }
};
// @lc code=end
