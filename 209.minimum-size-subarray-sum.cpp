/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>
#include <climits>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (right < nums.size())
        {
            sum += nums[right];

            while (sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
