/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s)
            freq1[c - 'a']++;

        for (char c : t)
            freq2[c - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
