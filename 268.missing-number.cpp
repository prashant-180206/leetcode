/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};
// @lc code=end
