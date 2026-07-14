/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> newnums;
        int uniqueElements = 0;
        for (int num : nums)
        {
            if (num == val)
            {
                continue;
            }
            newnums.push_back(num);
            uniqueElements++;
        }
        nums = newnums;
        return uniqueElements;
    }
};
// @lc code=end
