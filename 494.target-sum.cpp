/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
    int target = 0;

    int helper(vector<int> &arr, int idx, int currsum)
    {
        int n = arr.size();
        if (idx == n)
            return currsum == target;

        int minus = helper(arr, idx + 1, currsum - arr[idx]);
        int plus = helper(arr, idx + 1, currsum + arr[idx]);
        return minus + plus;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        this->target = target;
        return helper(nums, 0, 0);
    }
};
// @lc code=end
