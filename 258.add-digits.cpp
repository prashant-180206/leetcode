/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
    int digsum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int addDigits(int num)
    {
        int res = digsum(num);
        while (res >= 10)
            res = digsum(res);

        return res;
    }
};
// @lc code=end
