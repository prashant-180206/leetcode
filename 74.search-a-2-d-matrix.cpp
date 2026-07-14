/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int row = mid / cols;
            int col = mid % cols;

            int value = matrix[row][col];

            if (value == target)
                return true;
            else if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};
// @lc code=end
