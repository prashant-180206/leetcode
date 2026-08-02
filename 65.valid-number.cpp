/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isNumber(string s)
    {
        bool seenDig = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digAfterExp = true;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                seenDig = true;
                if (seenExp)
                    digAfterExp = true;
            }
            else if (c == '.')
            {
                if (seenExp || seenDot)
                    return false;
                seenDot = true;
            }
            else if (c == '+' || c == '-')
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == 'e' || c == 'E')
            {
                if (seenExp || !seenDig)
                    return false;
                seenExp = true;
                digAfterExp = false;
            }
            else
                return false;
        }

        return seenDig && digAfterExp;
    }
};
// @lc code=end
