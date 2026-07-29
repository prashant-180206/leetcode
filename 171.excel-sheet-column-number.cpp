/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (char ch : columnTitle)
            result = result * 26 + (ch - 'A' + 1);

        return result;
    }
};
// @lc code=end
