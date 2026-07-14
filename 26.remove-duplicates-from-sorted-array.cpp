/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int currentnum = INT_MIN;
        int ans = 0;

        vector<int> newnums;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != currentnum)
            {
                ans++;
                currentnum = nums[i];
                newnums.push_back(nums[i]);
            }
        }
        nums = newnums;
        return ans;
    }
};
// @lc code=end
