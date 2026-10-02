/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
     int maxRotateFunction(vector<int>& nums)
    {
        int n = nums.size();

        long long sum = 0;
        long long F = 0;

        // Calculate sum and F(0)
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            F += i * nums[i];
        }

        long long ans = F;

        // Calculate F(1), F(2), ...
        for (int i = n - 1; i > 0; i--)
        {
            F = F + sum - n * nums[i];
            ans = max(ans, F);
        }

        return ans;
    }
};
// @lc code=end

