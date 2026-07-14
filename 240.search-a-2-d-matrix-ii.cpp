/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int rows = mat.size(), cols = mat[0].size();

        int r = 0, c = cols - 1;
        while (r < rows && c >= 0)
        {
            int current = mat[r][c];
            if (current == target)
                return true;
            else if (current > target)
                c--;
            else
                r++;
        }
        return false;
    }
};
// @lc code=end
