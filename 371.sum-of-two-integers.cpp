/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        int ans = a;
        int carry = b;

        while (carry != 0)
        {
            int newAns = ans ^ carry;
            int newCarry = (ans & carry) << 1;

            ans = newAns;
            carry = newCarry;
        }

        return ans;
    }
};
// @lc code=end
