/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{

    void solve(int n, int open, int closed, string curr, vector<string> &ans)
    {
        if (curr.length() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        if (open > closed)
            solve(n, open, closed + 1, curr + ")", ans);

        if (open < n)
            solve(n, open + 1, closed, curr + "(", ans);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        solve(n, 0, 0, "", ans);
        return ans;
    }
};
// @lc code=end
