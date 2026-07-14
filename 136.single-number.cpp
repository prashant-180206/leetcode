/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i : nums)
        {
            ans = ans ^ i;
        }
        return ans;
    }
};
// @lc code=end
