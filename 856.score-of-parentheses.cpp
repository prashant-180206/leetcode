/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                depth++;
            else
            {
                depth--;

                if (s[i - 1] == '(')
                    score += (1 << depth);
            }
        }
        return score;
    }
};
// @lc code=end
