#include <climits>
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int reverse = 0, original = x;
        while (x > 0)
        {
            if (reverse > INT_MAX / 10) // Check for overflow
                return false;
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return original == reverse;
    }
};
// @lc code=end
