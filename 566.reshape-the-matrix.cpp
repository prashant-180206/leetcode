/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c));
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;

        for (int i = 0; i < m * n; i++)
        {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
// @lc code=end
