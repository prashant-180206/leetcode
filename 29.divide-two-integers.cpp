/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include <climits>
#include <cmath>

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            if ((dvs << i) <= dvd)
            {
                dvd -= (dvs << i);
                ans += (1LL << i);
            }
        }

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};
// @lc code=end
