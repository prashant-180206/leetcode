/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end
