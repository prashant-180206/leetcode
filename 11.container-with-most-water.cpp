/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int leftptr = 0;
        int rightptr = n - 1;
        int maxlen = 0;

        while (leftptr < rightptr)
        {
            int width = rightptr - leftptr;
            int h = min(height[leftptr], height[rightptr]);

            int area = width * h;
            maxlen = max(maxlen, area);

            height[leftptr] > height[rightptr] ? rightptr-- : leftptr++;
        }

        return maxlen;
    }
};
// @lc code=end
