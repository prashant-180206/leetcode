/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
        // int ans = -1;
        // int n = needle.length();
        // int currentptr = 0;
        // for (int i = 0; i <= haystack.length() - n; i++)
        // {
        //     int found = 1;
        //     for (int j = 0; j < n && (i + j) < haystack.length(); j++)
        //     {
        //         if (haystack[i + j] != needle[j])
        //         {
        //             found = 0;
        //             break;
        //         }
        //     }

        //     if (found == 1)
        //     {
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;
    }
};
// @lc code=end
