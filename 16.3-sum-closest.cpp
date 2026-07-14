/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int minClosest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; i++)
        {
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if (abs(target - sum) < abs(target - minClosest))
                    minClosest = sum;

                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else
                {
                    return sum;
                }
            }
        }
        return minClosest;
    }
};
// @lc code=end
