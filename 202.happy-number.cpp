/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution
{
    int nextNumber(int n)
    {
        int sum = 0;
        while (n)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = nextNumber(n);

        do
        {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
// @lc code=end
