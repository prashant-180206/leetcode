/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
    double posPow(double x, long long n)
    {
        long binform = n;
        double ans = 1;
        while (binform > 0)
        {
            if (binform % 2 == 1)
            {
                ans *= x;
            }
            binform /= 2;
            x *= x;
        }
        return ans;
    }

public:
    double myPow(double x, int n)
    {
        long long N=n;
        if (n < 0)
            return 1 / posPow(x, -N);

        return posPow(x, n);
    }
};
// @lc code=end
