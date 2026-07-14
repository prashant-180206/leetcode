/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int val : nums)
        {
            currentSum += val;
            maxSum = max(currentSum, maxSum);
            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};
// @lc code=end
