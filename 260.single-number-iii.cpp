/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorall = 0;
        for (int num : nums)
            xorall ^= num;

        unsigned int rightmost = (unsigned int)(xorall) & -(unsigned int)(xorall);
        int num1 = 0, num2 = 0;
        for (int num : nums)
        {
            if (num & rightmost)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};
    }
};
// @lc code=end
