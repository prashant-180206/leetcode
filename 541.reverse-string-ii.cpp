/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            int start = i;
            int end = min(i + k - 1, (int)s.size() - 1);

            reverse(s.begin() + start, s.begin() + end + 1);
        }

        return s;
    }
};
// @lc code=end
