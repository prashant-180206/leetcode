/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> s;
        string curr = "";

        int i = 0;
        while (i <= path.length())
        {
            if (i == path.size() || path[i] == '/')
            {
                if (curr == "..")
                {
                    if (!s.empty())
                        s.pop();
                }
                else if (curr != "" && curr != ".")
                {
                    s.push(curr);
                }

                curr = "";
            }
            else
            {
                curr += path[i];
            }
            i++;
        }

        vector<string> temp;

        while (!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }

        string ans = "";

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans += "/";
            ans += temp[i];
        }

        return ans == "" ? "/" : ans;
    }
};
// @lc code=end
