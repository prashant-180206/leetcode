/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
