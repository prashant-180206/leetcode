/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];

            if (mp.find(need) != mp.end())
            {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end
