/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <vector>
#include <string>
#include <algorithm>s
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i])
            i++;

        return first.substr(0, i);
    }
};
// @lc code=end
