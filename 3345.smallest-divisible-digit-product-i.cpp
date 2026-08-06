/*
 * @lc app=leetcode id=3345 lang=cpp
 *
 * [3345] Smallest Divisible Digit Product I
 */

// @lc code=start
class Solution
{
public:
    int digitProduct(int x)
    {
        int prod = 1;

        while (x > 0)
        {
            prod *= (x % 10);
            x /= 10;
        }

        return prod;
    }

    int smallestNumber(int n, int t)
    {
        while (true)
        {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }

        return -1;
    }
};
// @lc code=end
