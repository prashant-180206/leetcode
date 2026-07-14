/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
    bool isFreqSame(int a1[], int a2[])
    {
        for (int i = 0; i < 26; i++)
            if (a1[i] != a2[i])
                return false;

        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int freq[26] = {0};
        for (char val : s1)
        {
            freq[val - 'a']++;
        }

        int winSize = s1.length();

        for (int i = 0; i < s2.length(); i++)
        {
            int windowidx = 0, idx = i;
            int winfreq[26] = {0};
            while (windowidx < winSize && idx < s2.length())
            {
                winfreq[s2[idx] - 'a']++;
                windowidx++;
                idx++;
            }

            if (isFreqSame(winfreq, freq))
                return true;
        }
        return false;
    }
};
// @lc code=end
