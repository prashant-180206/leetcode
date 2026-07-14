/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        reverse(s.begin(), s.end());
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (ans == 0 && s[i] == ' ')
                continue;
            if (s[i] != ' ')
                ans++;
            else
                break;
        }
        return ans;
    }
};
// @lc code=end
