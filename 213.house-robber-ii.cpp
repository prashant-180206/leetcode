/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    int helper(vector<int> &arr, int st, int end)
    {
        int prev2 = arr[st];
        int prev1 = max(arr[st], arr[st + 1]);
        int res = prev1;

        for (int i = st + 2; i <= end; i++)
        {
            res = max(arr[i] + prev2, prev1);

            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }

public:
    int rob(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);

        return max(helper(arr, 0, n - 2), helper(arr, 1, n - 1));
    }
};
// @lc code=end
