/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int count = 0;

            for (int num : nums)
            {
                if ((num >> bit) & 1)
                    count++;
            }

            if (count % 3)
                ans |= (1 << bit);
        }

        return ans;
    }
};
// @lc code=end
