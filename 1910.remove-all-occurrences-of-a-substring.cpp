/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        bool hasPart = (s.find(part) < s.length());
        while (hasPart)
        {
            int stidx = s.find(part);
            int charlen = part.length();
            s.erase(stidx, charlen);
            hasPart = (s.find(part) < s.length());
        }

        return s;
    }
};
// @lc code=end
