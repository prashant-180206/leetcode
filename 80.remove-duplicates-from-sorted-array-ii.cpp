/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
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
        if (n <= 2)
            return n;

        int index = 2; // first two elements are always allowed

        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[index - 2])
            {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};
// @lc code=end
