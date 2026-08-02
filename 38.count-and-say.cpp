/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
    string next(const string &prev)
    {
        int currrep = 1;
        char prevchar = prev[0];
        string ans = "";
        ans.reserve(prev.length() * 2);
        for (int i = 1; i < prev.length(); i++)
        {
            if (prev[i] == prevchar)
                currrep++;
            else
            {
                ans += to_string(currrep) + prevchar;
                prevchar = prev[i];
                currrep = 1;
            }
        }
        ans += to_string(currrep) + prevchar;
        return ans;
    }

public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            ans = next(ans);
        }
        return ans;
    }
};
// @lc code=end
