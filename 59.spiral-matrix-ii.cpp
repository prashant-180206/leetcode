/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector(n, 0));
        int count = 1;

        int srow = 0;
        int erow = n - 1;
        int scol = 0;
        int ecol = n - 1;

        while (srow <= erow && scol <= ecol)
        {
            for (int i = scol; i <= ecol; i++)
                ans[srow][i] = count++;

            srow++;

            for (int i = srow; i <= erow; i++)
                ans[i][ecol] = count++;

            ecol--;

            if (srow <= erow)
            {
                for (int i = ecol; i >= scol; i--)
                    ans[erow][i] = count++;
                erow--;
            }
            if (scol <= ecol)
            {
                for (int i = erow; i >= srow; i--)
                    ans[i][scol] = count++;
                scol++;
            }
        }

        return ans;
    }
};
// @lc code=end
