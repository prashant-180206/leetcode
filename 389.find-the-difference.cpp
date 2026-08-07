/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
        {
            if (freq[c - 'a'] == 0)
                return c;
            freq[c - 'a']--;
        }

        return '\0';
    }
};
// @lc code=end
