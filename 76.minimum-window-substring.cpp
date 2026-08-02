/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tb, curr;
        for (char c : t)
            tb[c]++;

        int needEl = tb.size();
        int elCount = 0;
        int minlen = INT_MAX;

        int start = -1;

        int i = 0, j = 0;
        while (j < s.length())
        {
            char c = s[j];
            if (tb.count(c) != 0)
            {
                curr[c]++;
                if (curr[c] == tb[c])
                    elCount++;
            }
            while (elCount == needEl)
            {
                if (j - i+1 < minlen)
                {
                    minlen = j - i + 1;
                    start = i;
                }
                char c = s[i];
                if (tb.count(c))
                {
                    if (curr[c] == tb[c])
                        elCount--;

                    curr[c]--;
                }
                i++;
            }

            j++;
        }
        if (start == -1)
            return "";

        return s.substr(start, minlen);
    }
};
// @lc code=end
