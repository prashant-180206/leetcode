/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};
// @lc code=end
