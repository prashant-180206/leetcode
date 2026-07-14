/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int start = i + 1;
            int end = n - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum < 0)
                    start++;
                else if (sum > 0)
                    end--;
                else
                {
                    vector<int> v = {nums[i], nums[start], nums[end]};
                    ans.push_back(v);

                    while (start < end && nums[start] == nums[start + 1])
                        start++;
                    while (start < end && nums[end] == nums[end - 1])
                        end--;
                    start++;
                    end--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
