/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (i == s.length() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};
// @lc code=end
