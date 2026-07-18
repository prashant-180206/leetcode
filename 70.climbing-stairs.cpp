/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int curr = 1;
        int next = 2;

        for (int i = 2; i < n; i++)
        {
            int newnext = curr + next;
            curr = next;
            next = newnext;
        }

        return next;
    }
};
// @lc code=end
