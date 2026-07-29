/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result;
        while (columnNumber > 0)
        {
            columnNumber--;
            char ch = 'A' + (columnNumber % 26);
            result = ch + result;
            columnNumber /= 26;
        }
        return result;
    }
};
// @lc code=end
