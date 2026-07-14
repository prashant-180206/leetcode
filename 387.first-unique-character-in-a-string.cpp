/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (freq[c - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
