/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
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
        string ans = "";
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.length(); i++)
        {
            string word = "";
            while (i < s.length() && s[i] != ' ')
                word += s[i++];
            if (word.length() == 0)
                continue;
            reverse(word.begin(), word.end());
            ans += ' ' + word;
        }

        return ans.substr(1);
    }
};
// @lc code=end
