/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    vector<string> curr;

    void dfs(string &s, vector<string> &list, vector<string> &ans, int i = 0)
    {
        if (i > s.length())
            return;

        if (i == s.length())
        {
            string str = "";
            for (int j = 0; j < curr.size(); j++)
            {
                str += curr[j];
                if (j != curr.size() - 1)
                    str += " ";
            }
            ans.push_back(str);
            return;
        }

        for (auto &wrd : list)
        {
            int len = wrd.length();
            if (i + len > s.length())
                continue;
            if (s.substr(i, len) == wrd)
            {
                curr.push_back(wrd);
                dfs(s, list, ans, i + wrd.length());
                curr.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> ans;
        dfs(s, wordDict, ans);
        return ans;
    }
};
// @lc code=end

// @lc code=end
