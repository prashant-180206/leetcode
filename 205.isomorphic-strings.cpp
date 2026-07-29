/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map;

        for (int i = 0; i < s.length(); i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if (map.find(c1) != map.end())
            {
                if (map[c1] != c2)
                    return false;
            }
            else
            {
                for (const auto &pair : map)
                {
                    if (pair.second == c2)
                        return false;
                }
                map[c1] = c2;
            }
        }
        return true;
    }
};
// @lc code=end
