/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> s(jewels.begin(), jewels.end());

        int count = 0;

        for (char c : stones)
            if (s.count(c))
                count++;

        return count;
    }
};
// @lc code=end