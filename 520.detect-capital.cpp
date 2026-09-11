/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int upper = 0;

        for (char c : word)
            if (isupper(c))
                upper++;

        if (upper == word.size())
            return true;

        if (upper == 0)
            return true;

        if (upper == 1 && isupper(word[0]))
            return true;

        return false;
    }
};
// @lc code=end
