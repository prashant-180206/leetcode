/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int depth = 0;
        int ans = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
            }
            else
            {
                depth--;
                if (depth < 0)
                {
                    ans++;
                    depth = 0;
                }
            }
        }
        ans += depth;
        return ans;
    }
};
// @lc code=end
