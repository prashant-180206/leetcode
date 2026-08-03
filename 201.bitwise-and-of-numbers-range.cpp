/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = 1 << i;
            if ((left & bit) == (right & bit))
            {
                ans |= (left & bit);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
