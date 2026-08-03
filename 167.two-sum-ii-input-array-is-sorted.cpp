/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            else if (sum < target)
                l++;
            else
                r--;
        }
        return {};
    }
};
// @lc code=end
