/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int prevbit = n & 1;
        n >>= 1;

        while (n > 0)
        {
            int currbit = n & 1;
            if (currbit == prevbit)
                return false;
            prevbit = currbit;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end
